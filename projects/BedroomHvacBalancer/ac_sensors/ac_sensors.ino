#include <SFE_BMP180.h>
#include <Wire.h>
#include <SyrotaAutomation1.h>
#include "config.h"


SyrotaAutomation net = SyrotaAutomation(RS485_CONTROL_PIN);
SFE_BMP180 bmp180;

double pressureReading;
double tempReading;
unsigned long measureTime;
unsigned long timeToRead;

bmp180Data sensor [3];

// Buffer for char conversions
char buf [100];

void setup()
{
  pinMode(LED1_PIN, OUTPUT);
  pinMode(I2C_CONTROL_PIN0, OUTPUT);
  pinMode(I2C_CONTROL_PIN1, OUTPUT);
  digitalWrite(LED1_PIN, LOW);
  strcpy(net.deviceID, "BrAcSens");
  Serial.begin(14400);
  
  // Set sensor addresses
  sensor[0].s0=LOW; 
  sensor[0].s1=LOW;
  sensor[1].s0=HIGH; 
  sensor[1].s1=LOW;
  sensor[2].s0=LOW; 
  sensor[2].s1=HIGH;
}

void loop()
{
  if (net.messageReceived()) {
    if (net.assertCommand("debug")) {
      sprintf(buf, "%d deg/100 (%d ms ago); status: %d", (int)(sensor[0].temperature*100), (millis() - measureTime), sensor[0].status);
      net.sendResponse(buf);
    } else if (net.assertCommand("getPresVacuum")) {
      dtostrf(sensor[0].pressure, 6, 2, buf);
      net.sendResponse(buf);
    } else if (net.assertCommand("getTempVacuum")) {
      dtostrf(sensor[0].temperature, 4, 2, buf);
      net.sendResponse(buf);
    } else if (net.assertCommand("getPresIntake")) {
      dtostrf(sensor[1].pressure, 6, 2, buf);
      net.sendResponse(buf);
    } else if (net.assertCommand("getTempIntake")) {
      dtostrf(sensor[1].temperature, 4, 2, buf);
      net.sendResponse(buf);
    } else if (net.assertCommand("getPresSupply")) {
      dtostrf(sensor[2].pressure, 6, 2, buf);
      net.sendResponse(buf);
    } else if (net.assertCommand("getTempSupply")) {
      dtostrf(sensor[2].temperature, 4, 2, buf);
      net.sendResponse(buf);
    } else {
      net.sendResponse("Unrecognized command");
    }
  }
  if (millis() - measureTime > SAMPLE_INTERVAL) {
    readSensor(0);
    readSensor(1);
    readSensor(2);
    measureTime = millis();
  }
}

/**
 * Reads pressure from one of the sensors
 * S0 and S1 set according to 74HC4052 datasheet
 */
void readSensor(int sensorIndex)
{
  char status;
  digitalWrite(I2C_CONTROL_PIN0, sensor[sensorIndex].s0);
  digitalWrite(I2C_CONTROL_PIN1, sensor[sensorIndex].s1);
  
  if (!bmp180.begin()) {
    sensor[sensorIndex].status = 1;
    return;
  }
  // Read temperature
  status = bmp180.startTemperature();
  if (status == 0) {
    sensor[sensorIndex].status = 2;
    return;
  }
  delay(status);
  status = bmp180.getTemperature(sensor[sensorIndex].temperature);
  if (status == 0) {
    sensor[sensorIndex].status = 3;
    return;
  } 
          Serial.print("Temperature: ");
          Serial.print(sensor[sensorIndex].temperature,2);
          Serial.println(" C");
  // END read temperature
  
  // Read pressure
  status = bmp180.startPressure(3);
  if (status == 0) {
    sensor[sensorIndex].status = 4;
    return;
  }
  delay(status);
  status = bmp180.getPressure(sensor[sensorIndex].pressure, sensor[sensorIndex].temperature);
          Serial.print("Pressure: ");
          Serial.print(sensor[sensorIndex].pressure,2);
          Serial.println(" mb");
  if (status == 0) {
    sensor[sensorIndex].status = 5;
    return;
  } 
  // END read pressure
  
  sensor[sensorIndex].status = 0;
}
