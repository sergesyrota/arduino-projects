#include <SyrotaAutomation1.h>
#include "config.h"
#include <EEPROM.h>

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

// Values we store in EEPROM
int maxMotorRuntime;
int switchStopWindow;
int sensorThresholdDirection;
int bottomSensorThreshold;
int topSensorThreshold;

void setup()
{ 
  // Motor pins
  pinMode(MOTOR_ENABLE_PIN, OUTPUT);
  digitalWrite(MOTOR_ENABLE_PIN, LOW);
  pinMode(MOTOR_DIRECTION_PIN, OUTPUT);
  digitalWrite(MOTOR_DIRECTION_PIN, LOW);
  
  // Switch input
  pinMode(INPUT_UP_PIN, INPUT_PULLUP);
  pinMode(INPUT_DOWN_PIN, INPUT_PULLUP);
  lastSwitchState = getSwitchState();
  
  // Sensor pins
  pinMode(MOTION_PIN, INPUT);
  pinMode(OPTICAL_SENSOR_ENABLE_PIN, OUTPUT);
  
  cacheEepromValues();
  strcpy(net.deviceID, NET_ADDRESS);
  Serial.begin(9600);
}

void loop()
{
  if (net.messageReceived()) {
    if (net.assertCommand("debug")) {
//      SensorData_t one = readOptical(SENSOR_POSITION_BOTTOM_PIN);
//      SensorData_t two = readOptical(SENSOR_POSITION_TOP_PIN);
      sprintf(buf, "Rom values: %d %d %d %d %d", maxMotorRuntime, switchStopWindow, sensorThresholdDirection, bottomSensorThreshold, topSensorThreshold);
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
        net.sendResponse("0");
      } else {
        sprintf(buf, "%d", (millis() - lastMotionTime)/1000);
        net.sendResponse(buf);
      }
    } else if (net.assertCommandStarts("setEeprom:", buf)) {
      // Usage: /bin/runCommand DeviceAddr setEeprom:3d0010
      // each 2 characters after : represents (in hex notation, transfered in plain text) a byte to be written to EEPROM
      char tempString [2];
      for (int addr=0; addr<MEMORY_BYTES; addr++) {
        tempString[0] = buf[addr*2];
        tempString[1] = buf[(addr*2)+1];
        EEPROM.write(addr, (byte)strtol(tempString, NULL, 16));
      }
      cacheEepromValues();
      net.sendResponse("Settings saved");
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

void checkMotorStopConditions() {
  // Just in case, limit maximum roll in one direction
  if (millis() - lastSwitchTime > maxMotorRuntime) {
    motorStop();
  }
  
  SensorData_t led = readOptical();
  // Limit when we sense it has reached "destination"
  if (motorDirection == MOTOR_DIRECTION_UP) {
    if (sensorThresholdDirection == 0 && led.top < topSensorThreshold) {
      motorStop();
    } else if (sensorThresholdDirection == 1 && led.top > topSensorThreshold) {
      motorStop();
    }
  } else {
    if (sensorThresholdDirection == 0 && led.bottom < bottomSensorThreshold) {
      motorStop();
    } else if (sensorThresholdDirection == 1 && led.bottom > bottomSensorThreshold) {
      motorStop();
    }
  }
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

void cacheEepromValues()
{
  // See config.h for explanation on why we have calculations
  maxMotorRuntime = EEPROM.read(MAX_MOTOR_RUNTIME_ADDR) * 1000;
  switchStopWindow = EEPROM.read(SWITCH_STOP_WINDOW_ADDR) * 100;
  sensorThresholdDirection = EEPROM.read(SENSOR_THRESHOLD_DIRECTION);
  bottomSensorThreshold = EEPROM.read(BOTTOM_SENSOR_THRESHOLD_ADDR) * 256 + 
    EEPROM.read(BOTTOM_SENSOR_THRESHOLD_ADDR+1);
  topSensorThreshold = EEPROM.read(TOP_SENSOR_THRESHOLD_ADDR) * 256 + 
    EEPROM.read(TOP_SENSOR_THRESHOLD_ADDR+1);
}

SensorData_t readOptical()
{
  SensorData_t res;
  digitalWrite(OPTICAL_SENSOR_ENABLE_PIN, HIGH);
  delay(1);
  res.bottom = analogRead(SENSOR_POSITION_BOTTOM_PIN);
  res.top = analogRead(SENSOR_POSITION_TOP_PIN);
  digitalWrite(OPTICAL_SENSOR_ENABLE_PIN, LOW);
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
  if (getSwitchState() != lastSwitchState) {
    if (millis() - lastSwitchTime < switchStopWindow) {
      motorStop();
    } else {
      if (lastSwitchState == MOTOR_DIRECTION_DOWN) {
        motorDown();
      } else {
        motorUp();
      }
    }
    lastSwitchState = !lastSwitchState;
    lastSwitchTime = millis();
  }
}

// Have this function so that it's possible to use 3-way switch with middle position, if I'd like in the future
int getSwitchState()
{
  return digitalRead(INPUT_UP_PIN);
}

void motorStop()
{
  digitalWrite(MOTOR_ENABLE_PIN, LOW);
  digitalWrite(MOTOR_DIRECTION_PIN, LOW);
  motorRunning = false;
}

void motorUp()
{
  // Rolling up is the NC state of the relay, hence no power to relay coil
  digitalWrite(MOTOR_DIRECTION_PIN, LOW);
  delay(10); // give relay chance to switch, if it needs to
  digitalWrite(MOTOR_ENABLE_PIN, HIGH);
  motorRunning = true;
  motorDirection = MOTOR_DIRECTION_UP; // to match normal switch position indicating the direction
}

void motorDown()
{
  // Rolling up is the NC state of the relay, hence need to power relay to pull down
  digitalWrite(MOTOR_DIRECTION_PIN, HIGH);
  delay(10); // give relay chance to switch, if it needs to
  digitalWrite(MOTOR_ENABLE_PIN, HIGH);
  motorRunning = true;
  motorDirection = MOTOR_DIRECTION_DOWN; // to match normal switch position indicating the direction
}
