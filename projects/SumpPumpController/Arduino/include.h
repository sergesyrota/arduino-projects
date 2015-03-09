// Config version
#define CONFIG_VERSION "SP1"
// Acknowledge button pin
#define ACK_PIN 9
// Pin with buzzer output for sounding an alarm
#define BUZZ_PIN 5
// Ultrasonic HC-SR04 pins
#define ULTRASONIC_ECHO_PIN 8
#define ULTRASONIC_TRIG_PIN 7
// SyrotaAutomation parameters
#define RS485_CONTROL_PIN 2
#define NET_ADDRESS "SumpPump"
// Time the buzzer should cycle in on/off states (milliseconds)
#define BUZZ_CYCLE_TIME 500
// Number of AC pump cycles to wait to do another self test
#define SELFTEST_AC_CYCLES 30

// Pressure sensor related data
#define PRESSURE_SENSOR_PIN A0

// DC pump interface pins
#define BATTERY_VOLTAGE_PIN A7
#define DC_PUMP_VOLTAGE_PIN A6
#define DC_PUMP_TRIGGER_PIN 10

struct configuration_t {
  char checkVersion[4]; // This is for detection if we have right settings or not
  unsigned int alertBatteryVoltage; // mV
  int alertWaterLevel; // Distance to the sensor in CM when alert should be triggered
  unsigned long baudRate; // Serial/RS-485 rate: 9600, 14400, 19200, 28800, 38400, 57600, or 115200
  int acPumpOnThreshold; // reading of higher than this means pump is ON
  int alertPressureLevel; // reading of higher than this might indicate clogged pipe and needs to trigger an alarm
  int acPumpOnTimeWarning; // number of seconds AC pump can be on at a time before warning
  unsigned long selftestTimeBetween; // Minimum number of seconds between self tests
  byte selfTestTimeLimit; // Length of DC Pump self test, if depth measurement is not met (seconds)
  byte depthMeasureTime; // Frequency with which water level should be read (seconds)
};

// Alert reason codes
enum alertReason {
  WaterLevel = 0,
  DischargedBattery = 1,
  DcPumpMalfunction = 2, // When self test is not passing (due to weak battery or not enough pumped height)
  DcPumpActivated = 3, // When DC pump activated automatically, usually indicating AC pump failure
  AcPumpOverload = 4, // When AC pump runs for extended period of time
  HighPressure = 5, // When pressure in the pipe gets over certain limit
  ExternallyForced = 6 // When external command to sound alert arrives
};

// HC-SR04 related data
struct Range {
  // Time last reading was taken
  unsigned long timeTaken;
  // Distance to water as measured by the sensor
  int distance;
  // Observed water level highs and lows, to determine AC pump cycles
  int highs[2];
  int lows[2];
};

// Pressure sensor and AC pump data
struct AcPump {
  // Number of seconds pump was ON (just a counter)
  unsigned long onSeconds;
  // Number of on/off cycles
  unsigned int onCycles;
  // Last observed pressure
  int lastPressure;
  // Last switch ON time
  unsigned long switchOnTime;
  // Current state
  boolean currentlyOn;
};
 
// DC Pump self-test related data
struct Selftest {
  // Time last self test was ran
  unsigned long lastTestTime;
  // AC pump cycle number at the time of last test
  unsigned long acCycles;
  // starting and ending height of the test
  int startingHeight;
  int endingHeight;
  // Time it took to run the test
  unsigned long testLength;
  // Minimum battery voltage during and immediately after the test
  unsigned int batteryVoltageMv;
  // Self test outcome
  boolean passed;
  // Current state, true if self test is in progress
  boolean nowActive;
};

// Alert information
struct Alert {
  // Time alert was triggered
  unsigned long timeTriggered;
  // alert state
  boolean present;
  boolean acknowledged;
  // Condition that triggered the alert
  char condition[40];
  // Buzzer state
  byte buzzerState;
  // Buzzer state change time
  unsigned long buzzerChangeTime;
  
  alertReason reason;
};

