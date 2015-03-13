#define NET_ADDRESS "DiningBlinds"
#define CONFIG_VERSION "BL1"

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

struct configuration_t {
  char checkVersion[4]; // This is for detection if we have right settings or not
  int maxMotorRuntime; // Number of seconds to limit individual motor run to
  int switchStopWindow; // Number of milliseconds threshold to consider it stop command, rather than switch (e.g. double click speed)
  boolean sensorThresholdDirection; // 0 = less than; 1 = greater than
  int bottomSensorThreshold; // Value after which we assume blinds are at the bottom position
  int topSensorThreshold; // Same, but for top sensor
  unsigned long baudRate; // Serial/RS-485 rate: 9600, 14400, 19200, 28800, 38400, 57600, or 115200
};

struct SensorData_t {
  int bottom;
  int top;
};

