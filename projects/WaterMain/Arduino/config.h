#ifndef WaterMeterConfig_h
#define WaterMeterConfig_h

#define VALVE_CLOSE_PIN 5
#define VALVE_OPEN_PIN 6
#define METER_SENSOR_PIN A5
#define TEMP_SENSOR_PIN 9

#define VALVE_OPERATION_TIME 3000
#define TEMP_READ_INTERVAL 60000L

struct TempSensorData {
  unsigned long lastReadTime;
  int chk;
  int temp;
  int humidity;
};

#endif
