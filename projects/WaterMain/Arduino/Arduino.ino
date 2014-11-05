#include <dht11.h>
#include "WaterMeterCounter.h"
#include "SyrotaAutomation1.h"
#include "config.h"

WaterMeterCounter meter = WaterMeterCounter();
SyrotaAutomation net = SyrotaAutomation(2);

// Buffer for char conversions
char buf [40];

// Indicates if one of valve commands was sent and at what time (millis)
unsigned long valveCommandTime = 0L;
// DHT-11 data and lib
TempSensorData dhtData;
dht11 tempSensor;

void setup()
{
  pinMode(VALVE_CLOSE_PIN, OUTPUT);
  pinMode(VALVE_OPEN_PIN, OUTPUT);
  digitalWrite(VALVE_CLOSE_PIN, LOW);
  digitalWrite(VALVE_OPEN_PIN, LOW);
  readTemp();
  strcpy(net.deviceID, "WtrMn");
  Serial.begin(14400);
}

void loop()
{
  if (net.messageReceived()) {
    if (net.assertCommand("getCount")) {
      sprintf(buf, "%lu", meter.getCounter());
      net.sendResponse(buf);
    } else if (net.assertCommand("getTemp")) {
      sendClimateResponse(dhtData.temp);
    } else if (net.assertCommand("getHumidity")) {
      sendClimateResponse(dhtData.humidity);
    }  else if (net.assertCommand("valveClose")) {
      valveClose();
      net.sendResponse("OK");
    } else if (net.assertCommand("valveOpen")) {
      valveOpen();
      net.sendResponse("OK");
    } else {
      net.sendResponse("Unrecognized command");
    }
  }
  valveCheck();
  meter.reading(analogRead(METER_SENSOR_PIN));
  if (millis() - dhtData.lastReadTime > TEMP_READ_INTERVAL) {
    readTemp();
  }
}

void sendClimateResponse(int data)
{
  if (dhtData.chk == DHTLIB_OK) {
    sprintf(buf, "%d", data);
    net.sendResponse(buf);
  } else{
    sprintf(buf, "ERROR: %d", dhtData.chk);
    net.sendResponse(buf);
  }
}

void readTemp()
{
  dhtData.chk = tempSensor.read(TEMP_SENSOR_PIN);
  switch (dhtData.chk) {
    case DHTLIB_OK:
      dhtData.temp = tempSensor.temperature;
      dhtData.humidity = tempSensor.humidity;
      break;
    default:
      dhtData.temp = -1;
      dhtData.humidity = -1;
  }
  dhtData.lastReadTime = millis();
}

// Sends a command on the open pin
void valveOpen()
{
  digitalWrite(VALVE_CLOSE_PIN, LOW);
  digitalWrite(VALVE_OPEN_PIN, HIGH);
  valveCommandTime = millis();
}

// Sends a command on the close pin
void valveClose()
{
  digitalWrite(VALVE_OPEN_PIN, LOW);
  digitalWrite(VALVE_CLOSE_PIN, HIGH);
  valveCommandTime = millis();
}

// Disables valve pins after timeout
void valveCheck()
{
  if (valveCommandTime == 0L) {
    return;
  }
  if (millis() - valveCommandTime > VALVE_OPERATION_TIME) {
    digitalWrite(VALVE_CLOSE_PIN, LOW);
    digitalWrite(VALVE_OPEN_PIN, LOW);
    valveCommandTime = 0L;
  }
}

