
/*
  HumidityCheck.h - class to make decisions on triggering exhaust fan based on relative humidity reading
  
  Created by Serge Syrota, July 31, 2013.
*/

#ifndef HumidityCheck_h
#define HumidityCheck_h

#include <Arduino.h>
#include <dht11.h>
#include <Time.h>

class HumidityCheck
{
public:
	int errorBuzzerPin; // LED pin that would mean there was an error detected somewhere
        HumidityCheck(int pin); // Constructor, accepting pin number at which DHT11 sensor's data is connected
	boolean check(); // main method that should be called periodically that returns true if fan needs to be ON and false otherwise
private:
        long lastCalledTime; // use this to prevent refresh more than necessary
        
        /* Bunch of trend related variables and method */
        byte RHvalues[360]; // array containing all readings, will be cycled through when reaching the end
        static const int RHindexSize = 360; // constant containing size of the RHvalues, to avoid constant recalculations
        int RHindex; // Pointer to the next available index of RHvalues
        int RHindexFilled; // This will hold number of elements we've already filled our index with, so that we don't interpret 0 as a real value upon startup
        static const byte shortPeriod = 10; // How many previous reading to consider for short term trend
        static const byte longPeriod = 60; // How many previous reading to consider for long term trend
        static const byte readingPeriod = 0; // Minimum number of seconds between readings (lower number, more frequent readings)
        float getAverage(int numElements); // 

        /* Sensor related data */
        int dht11Pin; // pin to which DHT11 sensor's data is connected
	dht11 dht; // instance of the DHT11 library
	boolean dhtRead(); // Method that will read sensor data
        void addRhValue(int v); // This will and update index element respectively
	void errorBuzz(); // if error buzzer pin is set, this will produce a buzz on error
        float getTriggerRH(byte baseline); // calculates trigger RH based on a formula to give drier air more RH change before triggering, and moist air less so

	boolean fanOn; // current state of the fan, used to determine if we need to look for ON or OFF conditions
	long onTime; // second timestamp for when fan was last turned ON
        int triggeredHumidity; // Humidity at which fan was triggered to be ON, this is the target to get back to

};

#endif

