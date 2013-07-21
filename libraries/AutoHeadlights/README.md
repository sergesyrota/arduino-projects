Auto Headlights Library
================

This library implements an Auto Headlights feature in one of my projects. It can be adapted for other purposes as well.

Principle of work
-----------------

Library needs one analog input, and one digital output. Thresholds are set up to identify when digital output should be turned ON or OFF. Wiring is assumed in a way that higher reading would mean a need to turn sensor ON, and lower would mean turning it OFF. "Neutral" buffer is supported, where no action is desired, so output stays in the same state as it was before. Action delay is a configurable amount of time that needs to pass in a consistent "change desired" state before executing the request. See attached Application.PNG for suggested wiring. (NOTE: it assumes a need to ground your control wire, so make sure your application needs the same. If not - modify output control wiring as necessary.)

Features
--------

 * Neutral reading range is supported, so that only strong indication of desired change will be acted upon
 * Immediate action on startup: when sketch just starts running, desired action is applied within first 2 seconds of start, instead of using standard delay cycle
 * Delay time is configurable, so that change action is not executed immediately, but only after continuous reading of change desired during this period of time

Installation
------------

Download AutoHeadlights folder, and copy it to your Sketchbook's libraries folder. Restart Arduino IDE, and select Sketch -> Import Library... -> AutoHeadlights.
 
Arduino Sketch example
----------------------

	#include <AutoHeadlights.h>
	
	// A3 is the input pin of the sensor
	// Digital pin 6 is the one that control the headlights.
	AutoHeadlights headlight = AutoHeadlights(A3, 6);
	
	void setup() {
	  // Set thresholds for on and off readings
	  headlight.setSensorThreshold(300, 640);
	}

	void loop() {
	  headlight.run();
	  delay(500);
	}
	