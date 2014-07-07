#include "WaterMeterCounter.h"

WaterMeterCounter::WaterMeterCounter() // Constructor
{
    direction = RISING;
}

void WaterMeterCounter::reading(unsigned int data) // Records a reading, and does necessary processing
{
    if (direction == RISING) {
        if (extremum < data) {
            // Maintaining direction, just need to update extremum reading
            extremum = data;
        } else if ((extremum - data) >= CHANGE_THRESHOLD) {
            // We've moved beyond threshold. This indicates change of direction
            direction = FALLING;
            extremum = data;
            count++;
        }
    } else {
        if (extremum > data) {
            // Maintaining direction, just need to update extremum reading
            extremum = data;
        } else if ((data - extremum) >= CHANGE_THRESHOLD) {
            // We've moved beyond threshold. This indicates change of direction
            direction = RISING;
            extremum = data;
            count++;
        }
    }
}

unsigned long WaterMeterCounter::getCounter() // Gets current counter value
{
    return count;
}