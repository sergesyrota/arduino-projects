/*
  OneTouchLaneChange.cpp - library for facilitating one touch lane change feature.
  "Touch" turn signal (registered on one of the digital inputs), and it will stick for 
  a predetermined amount of time. Hold it for too long, and it will ignore the signal.
  Touch again (any of the turns) to cancel.
  Created by Serge Syrota, July 17, 2013.
*/

#include "Arduino.h"
#include "OneTouchLaneChange.h"

// Constructor just sets some default variables
// Required configuration needs to happen with addPair() call
OneTouchLaneChange::OneTouchLaneChange()
{
	currentPairIndex = 0;
	// Amount of time (in ms) to continue showing turn signal after it was determined we need to prolong it
	stickTime = 3000;
	// Amount of time within which ON and OFF needs to be registered to actually be treated as a lane change request
	// longer than that - and it's ignored
	ignoreThreshold = 300;
}

/**
 * Adds a pair of pins to be considered. Should be a pair: input and output.
 * Input connects directly to the physical switch
 * Output connects to the wire coming after the switch (e.g. to the turn module). This will carry true command.
 */
void OneTouchLaneChange::addPair(int in, int out)
{
	// Using struct to have all information in one place
	pairData pair;
	// Setting pinout for future use
	pair.inPin = in;
	pair.outPin = out;
	// initializing some default variables to keep everything consistent
	pair.stickRequestTime = 0;
	pair.expirationTime = 0;
	// Setting correct pin modes so that we can use them as needed.
	pinMode(pair.inPin, INPUT);
	pinMode(pair.outPin, OUTPUT);
	// synchronizing our perceived output state with actual one
	digitalWrite(pair.outPin, LOW);
	// Adding the pair to the array, and incrementing the index
	pairs[currentPairIndex] = pair;
	// This will allow us to keep adding, and will let us know how many pairs we have (although don't see why you have more than two)
	currentPairIndex++;
}

/**
 * This needs to be run periodically to analyze the state, make decisions, and execute it. 
 * I'd say it needs to run every ~50ms to make sure you dont have enough time in between 
 * ON and OFF signals to register both
 */
void OneTouchLaneChange::run()
{
	// We're reading all inputs at once, and storing them in the struct for further reuse. Easier than reading every time
	readInputs();
	// This will check if we had output ON before and need to turn it off by now
	checkExpiration();
	// If we still have any outputs active, then it's time to check if we have a request to cancel any.
	if (anyOutputsActive()) {
		checkCancelRequests();
	} else {
		// This will look for actual requests to enable lane change request, if we don't have anything on right now
		// If we do, it was a cancel request, so no need to bother
		checkLaneChangeRequests();
	}
}

/**
 * This will read all input pins, and store results in corresponding structs for future reference
 */
void OneTouchLaneChange::readInputs()
{
	// Loop through all signal input pins, and store current state
	int i;
	for (i=0; i<currentPairIndex; i++) {
		pairs[i].inValue = digitalRead(pairs[i].inPin);
	}
}

// Checks all pairs, looking for one with output set to HIGH and expiration time elapsed (e.g. need to turn off)
void OneTouchLaneChange::checkExpiration()
{
	int i;
	for (i=0; i<currentPairIndex; i++) {
		// outState will be synchronized with pin mode, if setOutput was used
		// expiration time should store point in milliseconds when it should beturned off. If we're past that point - rurn it off.
		if (pairs[i].outState == HIGH && pairs[i].expirationTime < millis()) {
			setOutput(i, LOW);
		}
	}
}

// Helper function to return true if ANY of all output pins we have in the system are set to HIGH
bool OneTouchLaneChange::anyOutputsActive()
{
	int i;
	for (i=0; i<currentPairIndex; i++) {
		if (pairs[i].outState == HIGH) {
			return true;
		}
	}
	return false;
}

// Checks all pairs, if finds any input as HIGH, all outputs need to be set to LOW
void OneTouchLaneChange::checkCancelRequests()
{
	int i;
	for (i=0; i<currentPairIndex; i++) {
		// readInputs should've updated all values in the struct, so we just use that
		if (pairs[i].inValue == HIGH) {
			cancelAll();
			// this expiration means that we ignore this pin's input as "stick request" "ignore threshold" amount of time
			// to prevent cancel request being treated as stick request
			pairs[i].expirationTime = millis() + ignoreThreshold;
			// we can return after first HIGH input is encountered, as everything is canceled now
			return;
		}
	}
}

/**
 * Main logic that actually looks for signals and interprets them as stick requests, or something to ignore.
 * Should be executed after we check for cancel requests, clean everything up, etc.
 */
void OneTouchLaneChange::checkLaneChangeRequests()
{
	int i;
	for (i=0; i<currentPairIndex; i++) {
		// input is detected on this pin, let's see if we need to ignore or something else
		if (pairs[i].inValue == HIGH) {
			if (pairs[i].stickRequestTime == 0) {
				// This means this is the first time we're seeing this request, so need to store the time stamp
				// of this request, so that we can analyze how long it was seen
				pairs[i].stickRequestTime = millis();
			}
		// If we don't have an input, and we are past the expiration time, then need to check if anything needs to be done
		} else if (pairs[i].expirationTime < millis()) {
			// Check if we actually had a request before. If we didn't, stickRequestTime would be set to 0
			if (pairs[i].stickRequestTime > 0) {
				// execute only if stick request started within ignoreThreshold - this is the time beyond which it's not stick request anymore
				if ((pairs[i].stickRequestTime + ignoreThreshold) > millis()) {
					stickSignal(i);
				// If we're past that, we need to mark all pins as ignored for a little bit
				// This prevents a condition, in which turn signal that is switched off after executing the turn
				// (e.g. that kicks back to neutral position when you unwind steering wheel) touches the other direction
				// slightly, and is being recognized as very quick stick request.
				// Since we don't have a concept of "opposite" signal, we just set it to all.
				} else {
					ignoreAll(ignoreThreshold);
				}
			}
			// this means our request expired, or never existed, so we can reset this to 0.
			pairs[i].stickRequestTime = 0;
		}
	}
}

// scrolls through all pairs, and sets ignore for requested period of time
void OneTouchLaneChange::ignoreAll(int time)
{
	long expiration = millis() + time;
	int i;
	for (i=0; i<currentPairIndex; i++) {
		// Expiration time holds a timestamp until which we should not process input from these pairs
		pairs[i].expirationTime = expiration;
	}
}

// scrolls through all pairs and sets them to LOW output, meaning everything off
void OneTouchLaneChange::cancelAll()
{
	int i;
	for (i=0; i<currentPairIndex; i++) {
		setOutput(i, LOW);
		// Reset stick request time just in case
		pairs[i].stickRequestTime = 0;
	}
}

// sets particular pair at a certain output state, and also stores this state in the struct for quick access
void OneTouchLaneChange::setOutput(int pairIndex, int targetState)
{
	digitalWrite(pairs[pairIndex].outPin, targetState);
	pairs[pairIndex].outState = targetState;
}

// routines and state changes to execute stick signal for a certain period of time
void OneTouchLaneChange::stickSignal(int pairIndex) 
{
	setOutput(pairIndex, HIGH);
	// expiration time also doubles as time after which we need to turn the signal off
	pairs[pairIndex].expirationTime = millis() + stickTime;
	pairs[pairIndex].stickRequestTime = 0;
}
