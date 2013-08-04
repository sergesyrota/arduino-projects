#include <Time.h>
#include "HumidityCheck.h"
#include <dht11.h>

// For some reason sketch won't compile without explicit inclusion in here
#if LOGGER
#include <SD.h>
#endif

/* Pinout */
#define DHT11PIN 5 // Data sensor for SHT11 sensor
#define OUTPUTPIN 4 // Pin that triggers the fan
#define ERRORBUZZERPIN 1 // Pin that is connected to the buzzer so that we can signal error
#define MOTIONPIN 6 // Pin that is connected to motion sensor output

// Initialize HumidityCheck
HumidityCheck rh = HumidityCheck(DHT11PIN);

// Timestamp of the last known triggered event.
long lastKnownTrigger = 0;
// Current state of the output pin
int currentState = LOW;

void setup() {
  //delay(2000);
  rh.errorBuzzerPin = ERRORBUZZERPIN;
  pinMode(OUTPUTPIN, OUTPUT);
  pinMode(MOTIONPIN, INPUT);
  Serial.begin(9600);
  Serial.println("Starting...");
}

void loop() {
  boolean triggerExists = (rh.check() || motionPresent());
  
  if (triggerExists) {
    // External trigger to enable fan operation exists at this very moment
    // Need to write down last known time
    lastKnownTrigger = now();
    // And set current state to HIGH
    currentState = HIGH;
    Serial.println("Trigger is ON right now");
  } else if (currentState == HIGH && (now()-lastKnownTrigger) > readDelaySwitch()) {
    // no external trigger, but the fan is ON now, and it's been ON for longer than the value set by the delay switch
    // This means we need to shut it off
    currentState = LOW;
    Serial.println("Delay timeout exceeded, so shutting it OFF");
  }
  // Synchronize current state, and call it a cycle.
  digitalWrite(OUTPUTPIN, currentState);
  
  Serial.print("Free memory: ");
  Serial.println(availableMemory());
  
  delay(1000);
}

// Reads motion sensor pin, and returns true or false depending on the reading
boolean motionPresent() {
  if (digitalRead(MOTIONPIN) == HIGH) {
    return true;
  } else {
    return false;
  }
}

// Reads input from the delay selector switch to specify delay after ON trigger
int readDelaySwitch() {
  return 10;
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

