#include <SyrotaAutomation1.h>
#include <SPI.h>
#include <RH_NRF24.h>

// Singleton instance of the radio driver
RH_NRF24 nrf24;
// Home network instance
SyrotaAutomation net = SyrotaAutomation(2);

// Buffer for char conversions
char buf [40];

struct TempSensorData {
  unsigned long lastReadTime;
  int temp; // divide by 10 to get temperature in celcius
  int humidity;
};

TempSensorData sensor[2];

void setup()
{
  strcpy(net.deviceID, "Bench");
  Serial.begin(14400);
  // Init RF module
  nrf24.init();
  nrf24.setChannel(1);
  nrf24.setRF(RH_NRF24::DataRate250kbps, RH_NRF24::TransmitPower0dBm);
}

void loop()
{
  if (net.messageReceived()) {
    if (net.assertCommand("getSens1")) {
      sprintf(buf, "age=%lu&temp=%d&hum=%d", (millis() - sensor[0].lastReadTime)/1000LU, sensor[0].temp, sensor[0].humidity);
      net.sendResponse(buf);
    } else if (net.assertCommand("getSens2")) {
      sprintf(buf, "age=%lu&temp=%d&hum=%d", (millis() - sensor[1].lastReadTime)/1000LU, sensor[1].temp, sensor[1].humidity);
      net.sendResponse(buf);
    } else {
      net.sendResponse("Unrecognized command");
    }
  }
  if (nrf24.available())
  {
    getRfData();
  }
}

void getRfData()
{
  uint8_t buf[5];
  uint8_t len = sizeof(buf);
  if (
       nrf24.recv(buf, &len) // Receive data
    && validateData(buf) // Validate checksum
    && buf[0]>0 // Make sure our device ID is at least 1
    && buf[0]<=(sizeof(sensor)/sizeof(sensor[0])) // Make sure received Device ID does not go out of array bounds
    )
  {
    byte sensId = buf[0]-1;
    sensor[sensId].lastReadTime = millis();
    sensor[sensId].temp = (buf[1]*256) + buf[2]; // Convert 2 bytes into one integer
    sensor[sensId].humidity = buf[3];
  }
}

boolean validateData(uint8_t* buf)
{
  unsigned int checkDigit = 0;
  checkDigit ^= buf[0];
  checkDigit ^= buf[1];
  checkDigit ^= buf[2];
  checkDigit ^= buf[3];
  return (checkDigit == buf[4]);
}
