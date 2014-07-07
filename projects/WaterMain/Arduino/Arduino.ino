#include "WaterMeterCounter.h"
#include "SyrotaAutomation1.h"

#define SENSOR_PIN A0

WaterMeterCounter meter = WaterMeterCounter();
SyrotaAutomation net = SyrotaAutomation(2);

// Buffer for char conversions
char buf [40];

void setup()
{
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
  meter.reading(analogRead(SENSOR_PIN));
}

