#define CONTROL_PIN 10
#define BTN_PIN 11
#define LIGHT_PIN A1

// How much daylight should we see to switch the lights ON
#define DAYLIGHT_TIMEOUT 10800000L // 3 hours
// Above this reading, we asusme the day has come
#define DAY_THRESHOLD 150
// Below this reading, we assume night fell
#define NIGHT_THRESHOLD 50

#define DAYTIME 1
#define NIGHTTIME 0

int lastKnownBtnState = LOW;
int currentLightState = LOW;
int lastKnownDayState = NIGHTTIME;
unsigned long daylightTime; // last known transition to daylight

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int buttonState = digitalRead(BTN_PIN);
  if (buttonState == LOW && lastKnownBtnState == HIGH) {
    // Button was pressed, switching the light
    switchLight();
  }
  lastKnownBtnState = buttonState;

  int lightData = analogRead(LIGHT_PIN);
  // Transition from night to day
  if (lightData > DAY_THRESHOLD && lastKnownDayState == NIGHTTIME) {
    lastKnownDayState = DAYTIME;
    daylightTime = millis();
  }
  // Transition to night
  if (lightData < NIGHT_THRESHOLD && lastKnownDayState == DAYTIME) {
    // If day lasted long enough, let's turn on the lights
    if ((millis() - daylightTime) > DAYLIGHT_TIMEOUT) {
      turnOn();
    }
    lastKnownDayState = NIGHTTIME;
  }
}



void switchLight()
{
  if (currentLightState == LOW) {
    turnOn();
  } else {
    turnOff();
  }
}

void turnOn()
{
  // To make it safe to use turn* multiple times in a row
  if (currentLightState == HIGH) {
    digitalWrite(CONTROL_PIN, HIGH);
    return;
  }
  for (int i=0; i<255; i++) {
    analogWrite(CONTROL_PIN, i);
    delay(2);
  }
  digitalWrite(CONTROL_PIN, HIGH);
  currentLightState = HIGH;
}

void turnOff()
{
  // To make it safe to use turn* multiple times in a row
  if (currentLightState == LOW) {
    digitalWrite(CONTROL_PIN, LOW);
    return;
  }
  for (int i=255; i>0; i--) {
    analogWrite(CONTROL_PIN, i);
    delay(2);
  }
  digitalWrite(CONTROL_PIN, LOW);
  currentLightState = LOW;
}
