#include "WaterMeterCounter.h"
#include "SyrotaAutomation1.h"
#include "config.h"

WaterMeterCounter meter = WaterMeterCounter();
SyrotaAutomation net = SyrotaAutomation(2);

// Buffer for char conversions
char buf [40];

void setup()
{
  pinMode(VALVE_CLOSE_PIN, OUTPUT);
  pinMode(VALVE_OPEN_PIN, OUTPUT);
  digitalWrite(VALVE_CLOSE_PIN, LOW);
  digitalWrite(VALVE_OPEN_PIN, LOW);
  
  strcpy(net.deviceID, "WtrMn");
  Serial.begin(14400);
}

void loop()
{
  if (net.messageReceived()) {
    if (net.assertCommand("getCount")) {
      sprintf(buf, "%d", meter.getCounter());
      net.sendResponse(buf);
    } else {
      net.sendResponse("Unrecognized command");
    }
  }
  meter.reading(analogRead(METER_SENSOR_PIN));
}

