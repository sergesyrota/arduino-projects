#include <DHT.h>
#include <SPI.h>
#include <RH_NRF24.h>

#define SENSOR_ID 2;

// Singleton instance of the radio driver
RH_NRF24 nrf24;
DHT dht;
unsigned int temp;
unsigned int hum;

void setup() 
{
  nrf24.init();
  nrf24.setChannel(1);
  nrf24.setRF(RH_NRF24::DataRate250kbps, RH_NRF24::TransmitPower0dBm);
  dht.setup(2, DHT::DHT22);
  Serial.begin(9600);
}

void loop()
{
  delay(dht.getMinimumSamplingPeriod());
  uint8_t data[5];
  packageData(data);
//  data[0]=0;
//  data[1]=230;
//  data[2]=39;
//  data[3]=193;
//  Serial.print("Temperature: ");
//  Serial.println(temp);
//  Serial.print("Data: ");
//  Serial.print(data[0]);
//  Serial.print("; ");
//  Serial.print(data[1]);
//  Serial.print("; ");
//  Serial.print(data[2]);
//  Serial.print("; ");
//  Serial.print(data[3]);
//  Serial.println(";");
  nrf24.send(data, sizeof(data));
  nrf24.waitPacketSent();
}

/*
 We can use 3 bytes to package all data. We need detailed temperature, but humidity without decimal is OK
 2 bytes for temperature
 1 byte for humidity
 1 byte for "checksum" (using XOR on 3 previous bytes)
*/
void packageData(uint8_t* outData)
{
  temp = 10*dht.getTemperature();
  hum = (int)dht.getHumidity();
  outData[0] = SENSOR_ID;
  outData[1] = (int)(temp/256);
  outData[2] = temp%256;
  outData[3] = hum;
  outData[4] = 0;
  outData[4] ^= outData[0];
  outData[4] ^= outData[1];
  outData[4] ^= outData[2];
  outData[4] ^= outData[3];
}
