#ifndef SelfTest_h
#define SelfTest_h

#include <Arduino.h>

class SelfTest
{
  public:
    SelfTest();
    // Time last self test was ran
    unsigned long lastTestTime;
    // AC pump cycle number at the time of last test
    unsigned long acCycles;
    // starting and ending height of the test
    int startingHeight;
    int endingHeight;
    // Time it took to run the test
    unsigned long testLength;
    // Battery voltage after the test
    unsigned int batteryVoltageMv;
    // Self test outcome
    boolean passed;
    // Current state, true if self test is in progress
    boolean nowActive;
};

#endif
