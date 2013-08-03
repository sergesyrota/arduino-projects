#include <Time.h>
#include "HumidityCheck.h"
#include <dht11.h>
#include <RunningAverage.h>


// Pinout */
#define DHT11PIN 5 // Data sensor for SHT11 sensor
#define OUTPUTPIN 13 // Pin that triggers the fan
#define ERRORLEDPIN 1 // Pin that is connected to LED signaling an error with the module

// Other config */
#define TRIGGERDIFF 1.1; // coefficient that would mean "rapid rise" in humidity

// Initialize HumidityCheck
HumidityCheck rh = HumidityCheck(1);


// Humidity restore value
float triggeredHumidity = 0.0F;

void setup() {
  //delay(2000);
  Serial.begin(9600);
  Serial.println("Starting...");
}

void loop() {
  boolean triggerExists = rh.check();
  if (triggerExists) {
    Serial.println("RH trigger is set to ON");
  } else {
    Serial.println("RH trigger is set to OFF OFF");
  }
  Serial.print("Free memory: ");
  Serial.println(availableMemory());
  
  delay(500);
  if (millis() > 10000) {
    //software_Reset();
  }
}

void software_Reset() // Restarts program from beginning but does not reset the peripherals and registers
{
  Serial.println("Rebooting!");
  delay(1000);
  asm volatile ("  jmp 0");  
}


// this function will return the number of bytes currently free in RAM
// written by David A. Mellis
// based on code by Rob Faludi http://www.faludi.com
int availableMemory() {
  int size = 1024; // Use 2048 with ATmega328
  byte *buf;

  while ((buf = (byte *) malloc(--size)) == NULL)
    ;

  free(buf);

  return size;
}

