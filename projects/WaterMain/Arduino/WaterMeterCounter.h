
#ifndef WaterMeterCounter_h
#define WaterMeterCounter_h

#define RISING 1
#define FALLING 0
#define CHANGE_THRESHOLD 3

class WaterMeterCounter
{
    public:
        WaterMeterCounter(); // Constructor
        void reading(unsigned int data); // Records a reading, and does necessary processing
        unsigned long getCounter(); // Gets current counter value
    private:
        unsigned long count; // Stores current counter (incremented with each reading extremum)
        unsigned int extremum; // Observed extremum so far
        int direction; // Indication of whether reading is rising or falling
};

#endif
