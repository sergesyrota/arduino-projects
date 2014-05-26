// Pin with buzzer output for sounding an alarm
#define BUZZ_PIN 5
// Time the buzzer should cycle in on/off states (milliseconds)
#define BUZZ_CYCLE_TIME 500
// Frequency with which water level should be read (seconds)
#define DEPTH_MEASURE_TIME 5
// Length of DC Pump self test, if depth measurement is not met (seconds)
#define SELFTEST_TIME_LIMIT 20
// Number of AC pump cycles to wait to do another self test
#define SELFTEST_AC_CYCLES 30
// Minimum number of seconds between self tests
#define SELFTEST_TIME_BETWEEN 86400UL // 3600 * 24 hours

// Pressure sensor related data
#define PRESSURE_SENSOR_PIN A0
#define AC_PUMP_ON_THRESHOLD 520 // reading of higher than this means pump is ON
#define ALERT_PRESSURE_LEVEL 600 // reading of higher than this might indicate clogged pipe and needs to trigger an alarm

// DC pump interface pins
#define BATTERY_VOLTAGE_PIN A3
#define DC_PUMP_VOLTAGE_PIN A1
#define DC_PUMP_TRIGGER_PIN 3

// Alert levels
#define ALERT_BATTERY_VOLTAGE 12000 // mV
#define ALERT_WATER_LEVEL -40 // Distance to the sensor in CM when alert should be triggered

// Alert reason codes
enum alertReason {
  WaterLevel,
  DischargedBattery,
  DcPumpActivated, // When DC pump activated automatically, usually indicating AC pump failure
  DcPumpMalfunction, // When self test is not passing (due to weak battery or not enough pumped height)
  HighPressure, // When pressure in the pipe gets over certain limit
  ExternallyForced // When external command to sound alert arrives
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
  // Condition that triggered the alert
  char condition[40];
  // Buzzer state
  byte buzzerState;
  // Buzzer state change time
  unsigned long buzzerChangeTime;
  
  alertReason reason;
};

