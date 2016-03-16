/*

motor: 28BYJ48-5V
  steps: 8
  stride angle: 5.625/64

  loops to 1 revolution: 360/(8 * 5.625/64) = 512

            | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 |
  4 orange  | x | x |   |   |   |   |   | x |
  ----------|---|---|---|---|---|---|---|---|
  3 yellow  |   | x | x | x |   |   |   |   |
  ----------|---|---|---|---|---|---|---|---|
  2 pink    |   |   |   | x | x | x |   |   |
  ----------|---|---|---|---|---|---|---|---|
  1 blue    |   |   |   |   |   | x | x | x |
  ----------|---|---|---|---|---|---|---|---|

Example:

@VENT01>set degrees: 90
@VENT01>set percents: 25

*/

#include <SyrotaAutomation1.h>

void motor_step_cw();
void motor_step_ccw();
bool motor_zero();
void motor_rotate_degrees(int degrees);
void motor_rotate_percents(int percents);
void motor_rotate_to(int position);

void set_error(char *message);

// Handles:
//   * set degrees: -360..360
//   * set percents: -100..100
void process_command();

int motor_position = 0;
// steps per rotation
const int motor_steps_per_rotation = 512;
const float motor_steps_per_degree = motor_steps_per_rotation / 360.0;

const int motor_sensor_pin = 2;
const int blink_pin = 13;

const int serial_pin = 3;
SyrotaAutomation net = SyrotaAutomation(serial_pin);
const char* net_address = "VENT01";


void setup() {
  // Serial
  Serial.begin(9600);

  // Error light
  pinMode(blink_pin, OUTPUT);
  digitalWrite(blink_pin, LOW);

  // Motor pins
  pinMode(8,  OUTPUT);
  pinMode(9,  OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);

  pinMode(motor_sensor_pin, INPUT);

  if(!motor_zero()) {
    set_error("Cannot zero motor!");
  }

  strcpy(net.deviceID, net_address);

  blink_happy();
  net.sendResponse("READY");

}

void loop() {
  // Example motor handling
  // delay(1000);
  // motor_rotate_to(128);
  // motor_rotate_degrees(90);
  // motor_rotate_percents(25);
  // delay(1000);
  // motor_rotate_to(0);
  // motor_rotate_degrees(0);
  // motor_rotate_percents(0);
  // delay(1000);

  if(net.messageReceived()) {
    process_command();
  }
}

// blink successfull init
void blink_happy() {
  for(int i = 0; i < 5; i++) {
    digitalWrite(blink_pin, HIGH);
    delay(100);
    digitalWrite(blink_pin, LOW);
    delay(50);
  }
}

// -----------

void process_command() {
  char buffer [100];
  long int value = 0;

  if(net.assertCommandStarts("set degrees:", buffer)) {
    value = strtol(buffer, NULL, 10);
    motor_rotate_degrees(value);
    net.sendResponse("OK");
    return;
  }

  if(net.assertCommandStarts("set percents:", buffer)) {
    value = strtol(buffer, NULL, 10);
    motor_rotate_percents(value);
    net.sendResponse("OK");
    return;
  }

  net.sendResponse("ERROR");
}

// ----------- MOTOR ROUTINES -------------

void motor_step_cw() {
  step1();
  step2();
  step3();
  step4();
  step5();
  step6();
  step7();
  step8();
}

void motor_step_ccw() {
  step8();
  step7();
  step6();
  step5();
  step4();
  step3();
  step2();
  step1();
}

void step1(){
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(2);
}
void step2(){
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(2);
}
void step3(){
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(2);
}
void step4(){
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(2);
}
void step5(){
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(2);
}
void step6(){
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  delay(2);
}
void step7(){
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(2);
}
void step8(){
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(2);
}

bool motor_zero() {
  for(int i = 0; i < motor_steps_per_rotation; i++) {
    motor_step_cw();
    if(digitalRead(motor_sensor_pin) == HIGH) {
      motor_position = 0;
      return true;
    }
  }
  return false;
}

void motor_rotate_to(int position) {
  int new_position = position % motor_steps_per_rotation;
  if(new_position > motor_position) {
    while(motor_position != new_position) {
      motor_step_cw();
      motor_position++;
    }
  } else {
    while(motor_position != new_position) {
      motor_step_ccw();
      motor_position--;
    }
  }
}

void motor_rotate_degrees(int degrees) {
  int new_position = (int) (motor_steps_per_degree * (degrees % 360));
  motor_rotate_to(new_position);
}

void motor_rotate_percents(int percents) {
  motor_rotate_to(motor_steps_per_rotation / 100.0 * (percents % 100));
}


// ----------- ERROR HANDLING ROUTINES -------------
void set_error(char* message) {
  char buffer[100];
  sprintf(buffer, "ERROR: %s", message);
  net.sendResponse(buffer);

  digitalWrite(blink_pin, HIGH);
  delay(100);

  exit(0);
}

