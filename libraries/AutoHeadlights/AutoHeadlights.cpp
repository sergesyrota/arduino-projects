/*
  AutoHeadlights.cpp - library for processing photo sensor input and
  automatically turning headlights on and off depending on the level
  of light read from the input.
  Created by Serge Syrota, July 17, 2013.
*/

#include "Arduino.h"
#include "AutoHeadlights.h"

// Constructor takes pinout for sensor (analog port) and output pin (relay or transistor) that will turn headlights on
AutoHeadlights::AutoHeadlights(int sensor, int output)
{
	sensorPin = sensor;
	outputPin = output;
	// some defaults
	pinMode(sensorPin, INPUT);
	pinMode(outputPin, OUTPUT);
	currentState = LOW;
	// Make sure to synchronize output pin with our current state
	digitalWrite(outputPin, currentState);
	// This is how much time needs to pass when a switch is desired to actually execute it, ms
	switchDelay = 15000;
}

// Sets thresholds for sensor reading to turn it on and off
void AutoHeadlights::setSensorThreshold(int on, int off)
{
	// If values were flipped, then let's flip them back just in case.
	// We always want to have a zone that is undecided to avoid flipping back and forth
	if (on > off) {
		int tmp;
		tmp = on;
		on = off;
		off = tmp;
	}
	lightsOnThreshold = on;
	lightsOffThreshold = off;
}

// This needs to be run periodically to analyze the state, make decisions, and execute it. 
// I'd say it needs to run with at most switchDelay/10 ms intervals
void AutoHeadlights::run()
{
	// getting what should be the desired state based on sensor reading and threshold values.
	// See getDesiredState() for more details
	if (currentState != getDesiredState()) {
		// This means this is the first time we get an indication of a state change, so need to store the time
		if (changeTime == 0) {
			changeTime = millis();
		// This means it's been long enough in the current state, so we need to execute it.
		// OR we've just started, so need to bring it to the desired state at about 2 seconds after start
		} else if ((millis() - changeTime) > switchDelay || (millis() > 1500 && millis() < 2000)) {
			changeState();
		}
	} else {
		// Resetting change time timer, to avoid flipping back and forth, and implement a delay feature
		// This means that if we venture into "desired switch" and then back into the neutral zone - we won't execute the switch
		// We'll actually need to be in the "desired switch" for switchDelay time consistently to actually switch
		changeTime = 0;
	}
}

// Reads sensor input, and makes a determination what is our current desired state
// It needs to be wired so that higher input values mean more visible light, and lower values mean darker environment
// When reading is in between threshold values, we're in the neutral zone. That means desired state is no change (e.g. current state)
int AutoHeadlights::getDesiredState()
{
	// Reading will product a number in 0..1024 range
	int sensorValue = analogRead(sensorPin);
	// If value is lower (e.g. it is darker) than your threshold for turning the lights on
	if (sensorValue < lightsOnThreshold) {
		// HIGH will mean we want to turn the headlights ON
		return HIGH;
	// If value is higher (e.g. it is brighter) than our OFF threshold
	} else if (sensorValue > lightsOffThreshold) {
		// LOW means turning the lights OFF
		return LOW;
	// If we're in limbo between the two, we don't want to change anything
	} else {
		// so whatever is set now is the state we want
		return currentState;
	}
}

// This will actually flip the state based on current one. If lights were on, we'll turn them off. And vice versa.
void AutoHeadlights::changeState() {
	// Set current state to the appropriate desired value
	if (currentState == HIGH) {
		currentState = LOW;
	} else {
		currentState = HIGH;
	}
	// after current state updated, apply the change, and reset timer back to 0, meaning no change indication observed
	digitalWrite(outputPin, currentState);
	changeTime = 0;
}