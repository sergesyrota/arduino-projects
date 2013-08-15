/*
  HumidityCheck.cpp - class to make decisions on triggering exhaust fan based on relative humidity reading
  
  Works by taking RH readings from DHT11 sensor periodically (specified in constants), then looking at the long term
  average, compared to short term average. If RH rises rapidly defined by getTriggerRH(baseline), then we will need
  to turn the fan on, and keep it on until it returns to the baseline.
  
  This will also produce a buzz when error occurs.
  
  Created by Serge Syrota, July 31, 2013.
*/

#include "HumidityCheck.h"

HumidityCheck::HumidityCheck(int pin)
{
  dht11Pin = pin;
  pinMode(dht11Pin, OUTPUT);
  fanOn = false; // initialize to FALSE just in case
#if LOGGER
  // Assumed SD card is connected to standard pins 10,11,12,13
  // PIN 9 is used for power for the SD card on my breakout
  pinMode(9, OUTPUT);
  digitalWrite(9, HIGH);
  pinMode(10, OUTPUT);
  if (!SD.begin(10)) {
    Serial.println("Card failed, or not present");
  } else {
    Serial.println("card initialized.");
  }
#endif
}

// Main function of the check, runs all logic, and returns desired state of the fan
boolean HumidityCheck::check()
{
  // Check if we're called sooner than necessary
  // This allows us to call check as often as we want, and we'll still enforce only fixed frequency
  // We're using Time library, so now() will return number of seconds, which is not going to rollover :)
  if (now() - lastCalledTime < readingPeriod) {
    // If nothing to do, then we just return previous calculation
    return fanOn;
  } else {
    // if enough time passed, we'll be proceeding, but need to update last called time accordingly
    // this was moved after we make sure our reading did not produce an error
  }
  // Get current measurements, and only proceed if they did not produce an error
  if (dhtRead()) {
    // Update called time, so that we prevent too frequent updates
    lastCalledTime = now();
    // Adding current reading to the array, so that we can calculate trends
    addRhValue(dht.humidity);
    // Set long and short averages to avoid constant recalculation
    float shortAverage = getAverage(shortPeriod);
    float longAverage = getAverage(longPeriod);
    float triggerRH;
    
    if (fanOn) {
      // We were sending ON signals before, let's check if OFF conditions are met
      if (shortAverage < triggeredHumidity) {
        // we've returned below the humidity that triggered the fan before, so can disable the fan
        fanOn = false;
      }
      // if it's been more than 4 hours and the fan is still on, then something went wrong, so let's disable it
      if ((now() - onTime) > (14400)) {
        fanOn = false;
      }
    } else {
      // Previous known state was OFF, so need to check for ON conditions
      // Get RH that we need to compare short term average to
      triggerRH = getTriggerRH(longAverage);
      
      if (shortAverage > triggerRH) {
        // Trigger condition reached
        // this will store humidity that we need to come back below to turn off the fan back; 
        // We're taking short term average humidity, as test shown that it's really hard to go back to the long term average
        // In case of taking a shower, for example, long term goes from 42 to 
        triggeredHumidity = shortAverage;
        // store current state and ON time for future reference
        onTime = now();
        fanOn = true;
        // return right now, as nothing more needs to be done
        return true;
      }
    }
#if LOGGER
    // Assemble data string for SD card logger
    String dataString = "";
    dataString += now();
    dataString += ",";
    dataString += String(dht.temperature);
    dataString += ",";
    dataString += String(dht.humidity);
    dataString += ",";
    dataString += (int)(shortAverage*100); // float to string is not supported
    dataString += ",";
    dataString += (int)(longAverage*100); // float to string is not supported
    dataString += ",";
    dataString += (int)(triggerRH*100); // float to string is not supported
    dataString += ",";
    if (fanOn) {
      dataString += "ON";
    } else {
      dataString += "OFF";
    }
    // And write this line in the file
    writeLog(dataString);
#endif
  } else {
#if LOGGER
    String dataString = "";
    dataString += now();
    dataString += ",ERROR READING SENSOR!";
    writeLog(dataString);
#endif
  }
  return fanOn;
}

// Writes a single line in the SD card log file
void HumidityCheck::writeLog(String line) {
#if LOGGER
    File dataFile = SD.open(LOGFILENAME, FILE_WRITE);
    
    // if the file is available, write to it:
    if (dataFile) {
      dataFile.println(line);
      dataFile.close();
      // print to the serial port too:
      Serial.println(line);
    }  
    // if the file isn't open, pop up an error:
    else {
      Serial.print("Error writing to ");
      Serial.println(LOGFILENAME);
    } 
#endif
}

// Calculates trigger RH, given the baseline
float HumidityCheck::getTriggerRH(byte baseline) {
  // This formula will roughly mean +10% RH for baseline of 10%, +5% RH for baseline of 40%, +3.5% for baseline of 80%
  float triggerRH = (float)baseline + ((float)10/sqrt(baseline*0.1));
  // 85 is the absolute max we want to consider for triggering, no matter the trend
  return min(85, triggerRH);
}

// Reads DHT11 sensor, and returns if it was successful or not
boolean HumidityCheck::dhtRead() {
  int chk = dht.read(dht11Pin);
  switch (chk)
  {
    case DHTLIB_OK: 
                // No error, we have data, so we're doing early return
                Serial.println("OK"); 
                return true;
    case DHTLIB_ERROR_CHECKSUM: 
                Serial.println("Checksum error"); 
                break;
    case DHTLIB_ERROR_TIMEOUT: 
                Serial.println("Time out error"); 
                break;
    default: 
                Serial.println("Unknown error"); 
                break;
  }
  // If we did not hit OK state (we should've returned from there) - we have an error of some sort, and need to signal it
  errorBuzz();
  return false;
}

// Produces a short error buzz to notify that this needs attention
void HumidityCheck::errorBuzz() {
  if (errorBuzzerPin) {
    pinMode(errorBuzzerPin, OUTPUT);
    tone(errorBuzzerPin, 523, 200);
  }
}

// Adds new reading to the array of previous values
void HumidityCheck::addRhValue(int v) {
  // RHindex shoudl be set to the next available cell, so writing new data right there
  RHvalues[RHindex] = v;
  // Incrementing for the next time
  RHindex++;
  // If we've reached the end (e.g. last index is size-1), looping back to the start
  if (RHindex >= RHindexSize) {
    RHindex=0;
  }
  // RHindexFilled contains a number that says how many elements were filled. Essentially we need to increment it
  // every time during the first pass of the loop. This allows us to calculate accurate averages on startup.
  if (RHindexFilled < RHindexSize) {
    RHindexFilled++;
  }
}

// Getting an average over the past X measurements
float HumidityCheck::getAverage(int numElements) {
  // If requested number of elements is more than amount of data points we already have in the array, then reduce to that
  if (numElements > RHindexFilled) {
    numElements = RHindexFilled;
  }
  // If number of measurements requested was more than total elements in the array, reset it to the number of elements instead
  if (numElements > RHindexSize) {
    numElements = RHindexSize;
  }
  // If it happened that we have 0 elements to analyze - return 0 right away
  if (numElements == 0) {
    return 0.0F;
  }
  // RHindex points to the next element to be overwritten (e.g. oldest element, or next empty, see addRhValue)
  // Need to start with one before that to have latest data
  int currentIndex = RHindex-1;
  // We'll store sum of all measurements in this variable
  long sum = 0;
  // i variable is not used, just need to iterate this many times over an array
  // We'll go down on index values until we have enough for our average
  for (int i=0; i<numElements; i++) {
    // Make sure to adjust the index pointing at the last array element if we've reached the bottom
    if (currentIndex < 0) {
      currentIndex = RHindexSize-1;
    }
    // Add value to the sum, and don't forget to decrement current index so that we have accurate position for the next run
    sum += RHvalues[currentIndex];
    currentIndex--;
  }
  // Returning explicit float, which is going to be an average of the elements
  return (float)sum / numElements;
}
