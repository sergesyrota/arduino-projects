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
  ExternallyForced // When external command to sound alert arrives
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

