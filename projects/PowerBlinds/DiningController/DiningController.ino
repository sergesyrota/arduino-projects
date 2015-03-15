#include <SyrotaAutomation1.h>
#include "config.h"
#include <EEPROMex.h>

SyrotaAutomation net = SyrotaAutomation(RS485_CONTROL_PIN);

// Buffer for char conversions
char buf [100];

// Other runtime variables
unsigned long lastSwitchTime;
boolean lastSwitchState;
boolean motorRunning;
boolean motorDirection;
boolean motionSensorStatus;
unsigned long lastMotionTime;
int knownBlindsPosition = -1; // Extra protection HIGH = rolled up, LOW = rolled down, -1 = unknown

// Values we store in EEPROM
struct configuration_t conf = {
  CONFIG_VERSION,
  // Default values for config
  10, //int maxMotorRuntime; // Number of seconds to limit individual motor run to
  200, //int switchStopWindow; // Number of milliseconds threshold to consider it stop command, rather than switch (e.g. double click speed)
  700, //int bottomSensorThreshold; // Value after which we assume blinds are at the bottom position
  500, //int topSensorThreshold; // Difference between A & B to assume reaching the top
  100, //int delayAfterReachingPosition; // After optical sensor identifies target position was reached - roll for a little more to get past the edge
  9600 //unsigned long baudRate; // Serial/RS-485 rate: 9600, 14400, 19200, 28800, 38400, 57600, or 115200
};

void setup()
{ 
  readConfig();
  // Motor pins
  pinMode(MOTOR_ENABLE_PIN, OUTPUT);
  digitalWrite(MOTOR_ENABLE_PIN, LOW);
  pinMode(MOTOR_DIRECTION_PIN, OUTPUT);
  digitalWrite(MOTOR_DIRECTION_PIN, LOW);
  
  // Switch input
  pinMode(INPUT_SWITCH_PIN, INPUT);
  lastSwitchState = getSwitchState();
  
  // Sensor pins
  pinMode(MOTION_PIN, INPUT);
  pinMode(OPTICAL_SENSOR_ENABLE_PIN, OUTPUT);
  
  strcpy(net.deviceID, NET_ADDRESS);
  Serial.begin(conf.baudRate);
}

void readConfig()
{
  // Check to make sure config values are real, by looking at first 3 bytes
  if (EEPROM.read(0) == CONFIG_VERSION[0] &&
    EEPROM.read(1) == CONFIG_VERSION[1] &&
    EEPROM.read(2) == CONFIG_VERSION[2]) {
    EEPROM.readBlock(0, conf);
  } else {
    // Configuration is invalid, so let's write default to memory
    saveConfig();
  }
}

void saveConfig()
{
  EEPROM.writeBlock(0, conf);
}

void loop()
{
  if (net.messageReceived()) {
    if (net.assertCommand("getSensors")) {
      SensorData_t sensAmbient = readOptical(true);
      SensorData_t sens = readOptical();
      sprintf(buf, "A: %d / %d; B: %d / %d;", 
        sensAmbient.a,
        sens.a,
        sensAmbient.b,
        sens.b);
      net.sendResponse(buf);
    } else if (net.assertCommand("rollUp")) {
      // Since we have time limits, we need to reset switch time
      lastSwitchTime = millis();
      motorUp();
      net.sendResponse("OK");
    } else if (net.assertCommand("rollDown")) {
      // Since we have time limits, we need to reset switch time
      lastSwitchTime = millis();
      motorDown();
      net.sendResponse("OK");
    } else if (net.assertCommand("timeSinceMotion")) {
      if (motionSensorStatus == HIGH) {
        net.sendResponse("0s");
      } else {
        sprintf(buf, "%ds", (millis() - lastMotionTime)/1000);
        net.sendResponse(buf);
      }
    } else if (net.assertCommand("debug")) {
      sprintf(buf, "Conf: %d %d %d %d", 
        conf.maxMotorRuntime, 
        conf.switchStopWindow, 
        conf.bottomSensorThreshold, 
        conf.topSensorThreshold);
      net.sendResponse(buf);
    } else if (net.assertCommandStarts("set", buf)) {
      processSetCommands();
    } else {
      net.sendResponse("Unrecognized command");
    }
  }
  readSwitch();
  readMotion();
  if (motorRunning) {
    checkMotorStopConditions();
  }
}

void processSetCommands()
{
  if (net.assertCommandStarts("setMaxMotorRuntime:", buf)) {
    unsigned int tmp = strtol(buf, NULL, 10);
    if (tmp > 0 && tmp < 300) {
      conf.maxMotorRuntime = tmp;
      saveConfig();
      net.sendResponse("OK");
    } else {
      net.sendResponse("ERROR");
    }
  } else if (net.assertCommandStarts("setSwitchStopWindow:", buf)) {
    unsigned int tmp = strtol(buf, NULL, 10);
    if (tmp > 0 && tmp < 1000) {
      conf.switchStopWindow = tmp;
      saveConfig();
      net.sendResponse("OK");
    } else {
      net.sendResponse("ERROR");
    }
  } else if (net.assertCommandStarts("setBottomSensorThreshold:", buf)) {
    unsigned int tmp = strtol(buf, NULL, 10);
    if (tmp > 0 && tmp < 1025) {
      conf.bottomSensorThreshold = tmp;
      saveConfig();
      net.sendResponse("OK");
    } else {
      net.sendResponse("ERROR");
    }
  } else if (net.assertCommandStarts("setTopSensorThreshold:", buf)) {
    unsigned int tmp = strtol(buf, NULL, 10);
    if (tmp > 0 && tmp < 1025) {
      conf.topSensorThreshold = tmp;
      saveConfig();
      net.sendResponse("OK");
    } else {
      net.sendResponse("ERROR");
    }
  } else if (net.assertCommandStarts("setOpticalDelay:", buf)) {
    unsigned int tmp = strtol(buf, NULL, 10);
    if (tmp > 0 && tmp <= 2000) {
      conf.delayAfterReachingPosition = tmp;
      saveConfig();
      net.sendResponse("OK");
    } else {
      net.sendResponse("ERROR");
    }
  } else if (net.assertCommandStarts("setBaudRate:", buf)) {
    long tmp = strtol(buf, NULL, 10);
    // Supported: 9600, 14400, 19200, 28800, 38400, 57600, or 115200
    if (tmp == 9600 ||
      tmp == 14400 ||
      tmp == 19200 ||
      tmp == 28800 ||
      tmp == 38400 ||
      tmp == 57600 ||
      tmp == 115200
    ) {
      conf.baudRate = tmp;
      saveConfig();
      net.sendResponse("OK");
      Serial.end();
      Serial.begin(tmp);
    } else {
      net.sendResponse("ERROR");
    }
  } else {
    net.sendResponse("Unrecognized command");
  }
}

void checkMotorStopConditions() {
  // Just in case, limit maximum roll in one direction
  if (millis() - lastSwitchTime > conf.maxMotorRuntime*1000) {
    motorStop();
    knownBlindsPosition = -1;
  }
  
  SensorData_t led = readOptical();
  // Limit when we sense it has reached "destination"
  if (motorDirection == MOTOR_DIRECTION_UP && abs(led.a-led.b) > conf.topSensorThreshold) {
    stopOnOptical(HIGH);  
  } else if (motorDirection == MOTOR_DIRECTION_DOWN && led.b > conf.bottomSensorThreshold) {
    stopOnOptical(LOW);
  }
}

void stopOnOptical(int knownPosition)
{
  delay(conf.delayAfterReachingPosition);
  motorStop();
  knownBlindsPosition = knownPosition;
}

void readMotion()
{
  if (motionSensorStatus != digitalRead(MOTION_PIN)) {
    motionSensorStatus = !motionSensorStatus;
    if (motionSensorStatus == LOW) {
      lastMotionTime = millis();
    }
  }
}

SensorData_t readOptical()
{
  return readOptical(false);
}

SensorData_t readOptical(boolean ambient)
{
  SensorData_t res;
  if (!ambient) {
    digitalWrite(OPTICAL_SENSOR_ENABLE_PIN, HIGH);
    delay(1);
  }
  res.b = analogRead(SENSOR_POSITION_B_PIN);
  res.a = analogRead(SENSOR_POSITION_A_PIN);
  digitalWrite(OPTICAL_SENSOR_ENABLE_PIN, LOW);
  // Just so that we're not illuminating all the time. Preserving LEDs, you know...
  delay(10);
  return res;
}

// Switch logic
/*
If switch was changed:
 - If time since last change is less than X
   = Stop motor, and do nothing
 - else
   = Start roll in the needed direction
 - Record time of change
*/
void readSwitch()
{
  int currentSwitchState = getSwitchState();
  if (currentSwitchState != lastSwitchState) {
    if (millis() - lastSwitchTime < conf.switchStopWindow) {
      motorStop();
      knownBlindsPosition = -1;
    } else {
      if (currentSwitchState == MOTOR_DIRECTION_DOWN) {
        motorDown();
      } else {
        motorUp();
      }
    }
    lastSwitchState = currentSwitchState;
    lastSwitchTime = millis();
  }
}

// Have this function so that it's possible to use 3-way switch with middle position, if I'd like in the future
int getSwitchState()
{
  return digitalRead(INPUT_SWITCH_PIN);
}

void motorStop()
{
  digitalWrite(MOTOR_ENABLE_PIN, LOW);
  digitalWrite(MOTOR_DIRECTION_PIN, LOW);
  motorRunning = false;
}

void motorUp()
{
  // Extra protection. If we know blinds are already up, not engage roll up
  if (knownBlindsPosition == HIGH) {
    return;
  }
  // Reset known position, as we're on the move!
  knownBlindsPosition = -1;
  // Rolling up is the NC state of the relay, hence no power to relay coil
  digitalWrite(MOTOR_DIRECTION_PIN, LOW);
  delay(10); // give relay chance to switch, if it needs to
  digitalWrite(MOTOR_ENABLE_PIN, HIGH);
  motorRunning = true;
  motorDirection = MOTOR_DIRECTION_UP; // to match normal switch position indicating the direction
}

void motorDown()
{
  // Extra protection. If we know blinds are already up, not engage roll up
  if (knownBlindsPosition == LOW) {
    return;
  }
  // Reset known position, as we're on the move!
  knownBlindsPosition = -1;
  // Rolling up is the NC state of the relay, hence need to power relay to pull down
  digitalWrite(MOTOR_DIRECTION_PIN, HIGH);
  delay(10); // give relay chance to switch, if it needs to
  digitalWrite(MOTOR_ENABLE_PIN, HIGH);
  motorRunning = true;
  motorDirection = MOTOR_DIRECTION_DOWN; // to match normal switch position indicating the direction
}
