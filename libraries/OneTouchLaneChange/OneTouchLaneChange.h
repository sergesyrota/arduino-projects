/*
  OneTouchLaneChange.h - library for facilitating one touch lane change feature.
  "Touch" turn signal (registered on one of the digital inputs), and it will stick for 
  a predetermined amount of time. Hold it for too long, and it will ignore the signal.
  Touch again (any of the turns) to cancel.
  Created by Serge Syrota, July 17, 2013.
*/
#ifndef OneTouchLaneChange_h
#define OneTouchLaneChange_h

#include "Arduino.h"

typedef struct {
	int inPin;
	int outPin;
	int inValue;
	int outState;
	long expirationTime;
	long stickRequestTime;
} pairData;

class OneTouchLaneChange {
	public:
		OneTouchLaneChange();
		int stickTime;
		int ignoreThreshold;
		void addPair(int in, int out);
		void run();
	private:
		pairData pairs[2];
		int currentPairIndex;
		void readInputs();
		void checkExpiration();
		bool anyOutputsActive();
		void checkCancelRequests();
		void checkLaneChangeRequests();
		void ignoreAll(int time);
		void cancelAll();
		void setOutput(int pairIndex, int targetState);
		void stickSignal(int pairIndex);
};

#endif