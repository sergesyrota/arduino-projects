#define SENSOR_PIN A0
#define HIGH_ZONE 522
#define LOW_ZONE 502

int currentState;
unsigned long counter = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  readMagnet();
}

void readMagnet()
{
  int field = analogRead(SENSOR_PIN);
  int state;
  // Magnetic field read is split in 3 zones: definite LOW, unknown (e.g. maintain), and definite HIGH
  if (field >= HIGH_ZONE) {
    state = HIGH;
  } else if (field <= LOW_ZONE) {
    state = LOW;
  } else {
    // Nothing changed, so we can exit
    return;
  }
  // If we've changed states, need to increment the counter
  if (state != currentState) {
    counter++;
    currentState = state;
  }
}
