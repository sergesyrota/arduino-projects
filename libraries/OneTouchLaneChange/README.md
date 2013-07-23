One Touch Lane Change Library
=============================

This library implements One Touch Lane Change feature in one of my projects. It can be adapted for other purposes as well.

Principle of work
-----------------

Library is set up to work with a collection of pairs: digital input and digital output. Digital input is a signal coming from a turn signal switch, and digital output operates a mechanism that sends supplemental or overriden signal to the car's module that operates turn indicators (more on wiring below). When INPUT is detected for less than 300ms (configurable), it is assumed to be "Lane Change" request, which enables the OUTPUT pin of the same pair for the next 3 seconds (also configurable). If the input was longer than 300ms, then it's assumed it was turn signal, instead of lane change, and it is ignored. If INPUT is detected while an override is engaged on one of the pins, all overrides are disabled (e.g. it's a cancel request).

Wiring details and hardware components
--------------------------------------

See suggested application for a reference. Library assumes that it is possible to differentiate (when override is engaged) between ON and OFF positions of turn switch. In other words, the wire coming from turn signal is cut so that output does not short back to the input. It also assumes ON is HIGH, while OFF is LOW on the input (and same for output).

In my example, i used a double throw relay, which connects switch and signal wires together when module is not engaged (e.g. normal operation), and connects +12V to the output when override is engaged. It is possible to achieve all same features without cutting the wire. All that needs to be done, is ignoring INPUT on the same pair override is engaged. Cancel feature still can be used by touching the opposite turn. 

2 resistors (270k in my application) are really don't have to be that. Just something that would be high enough not to drain too much juice. Probably 10k and up would do. You also have to connect INPUT pin to GND when switch is not engaged. second resistor is to ensure that when the switch is engaged and there is +12V on SW contact, you're not short circuiting everything back to ground.

Features
--------

 * Differentiation between lane change and turn signal.
 * Kickback prevention: when switch is kicked back into neutral position by unwinding the steering wheel after the turn, it may touch other direction's contact just briefly. This is ignored, and not recognized as lane change signal.
 * Cancel request: if you started showing turn signal in one direction and changed your mind, touch again (or in the opposite direction) to cancel
 
Installation
------------

Download OneTouchLaneChange folder, and copy it to your Sketchbook's libraries folder. Restart Arduino IDE, and select Sketch -> Import Library... -> OneTouchLaneChange.
 
Arduino Sketch example
----------------------

	#include <OneTouchLaneChange.h>

	OneTouchLaneChange lane = OneTouchLaneChange();

	void setup() {
	  // Configuration for lane change module
	  // input and output pins respectively
	  lane.addPair(8,9);
	  lane.addPair(7,10);
	}

	void loop() {
	  lane.run();
	  // 50ms delays between checks work well for me.
	  delay(50);
	}
