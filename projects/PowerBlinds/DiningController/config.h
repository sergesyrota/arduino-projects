#define NET_ADDRESS "DiningBlinds"

#define RS485_CONTROL_PIN 2
#define MOTION_PIN 12
#define LIGHT_PIN A2
#define CURRENT_PIN A5
#define MOTOR_ENABLE_PIN 5
#define MOTOR_DIRECTION_PIN 6
#define INPUT_UP_PIN 3
#define INPUT_DOWN_PIN 4
// Direction flags. Should coincide with boolean flags from digitalRead()
#define MOTOR_DIRECTION_UP LOW
#define MOTOR_DIRECTION_DOWN HIGH
#define OPTICAL_SENSOR_ENABLE_PIN 13
#define SENSOR_POSITION_BOTTOM_PIN A3
#define SENSOR_POSITION_TOP_PIN A0

// EEPROM values
#define MEMORY_BYTES 7
// Maximum runtime for a motor to go in one direction, regardless of sensor inputs (seconds)
#define MAX_MOTOR_RUNTIME_ADDR 0
// If switch changes position in this amount of time, consider it a stop command instead
// in 1/10th of a second
#define SWITCH_STOP_WINDOW_ADDR 1
// Sensor threshold direction (0 = less than; 1 = greater than)
#define SENSOR_THRESHOLD_DIRECTION 2
// Sensor threshold values, 2 bytes each
#define BOTTOM_SENSOR_THRESHOLD_ADDR 3
#define TOP_SENSOR_THRESHOLD_ADDR 5

struct SensorData_t {
  int before;
  int after;
};

