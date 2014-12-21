#define NET_ADDRESS "BrAcSens"

#define I2C_CONTROL_PIN0 12
#define I2C_CONTROL_PIN1 10
#define RS485_CONTROL_PIN 2
#define LED1_PIN 5
#define LED2_PIN 6
#define LED3_PIN 7
#define BUZZER_PIN 11

#define SAMPLE_INTERVAL 5000

struct bmp180Data {
  double temperature;
  double pressure;
  // Address on I2C multiplexer
  byte s0;
  byte s1;
  // 0: OK
  // 1: begin() failed
  // 2: cannot start temperature
  // 3: cannot read temperature
  // 4: cannot start pressure
  // 5: cannot read pressuve
  int status;
};

