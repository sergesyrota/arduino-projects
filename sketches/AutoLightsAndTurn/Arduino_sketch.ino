#include <OneTouchLaneChange.h>
#include <AutoHeadlights.h>

// Initializing auto headlights class.
// A3 is the input pin of the sensor
// Digital pin 6 is the one that control the headlights.
AutoHeadlights headlight = AutoHeadlights(A3, 6);

OneTouchLaneChange lane = OneTouchLaneChange();

void setup() {
  // Set thresholds for on and off readings
  headlight.setSensorThreshold(300, 500);
  // Override default delay, 5 sec should be better.
  headlight.switchDelay = 5000;
  
  // Configuration for lane change module
  // input and output pins respectively
  lane.addPair(8,9);
  lane.addPair(7,10);
}


void loop() {
  lane.run();
  headlight.run();
  delay(50);
}
