/*
  AutoHeadlights.h - library for processing photo sensor input and
  automatically turning headlights on and off depending on the level
  of light read from the input.
  Created by Serge Syrota, July 17, 2013.
*/
#ifndef AutoHeadlights_h
#define AutoHeadlights_h

#include "Arduino.h"

class AutoHeadlights {
	public:
		int switchDelay;
		AutoHeadlights(int sensor, int output);
		void setSensorThreshold(int on, int off);
		void run();
	private:
		int sensorPin;
		int outputPin;
		int currentState;
		int lightsOnThreshold;
		int lightsOffThreshold;
		long changeTime;
		int getDesiredState();
		void changeState();
};

#endif