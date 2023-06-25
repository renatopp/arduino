const int relayOut = 5;
const unsigned long timeOff = 60000; // 1 minute
const unsigned long timeOn = 60000; // 1 minute

bool initialized = false;
bool on = false;
unsigned long previousMillis = 0;
unsigned long interval = timeOn;

void setup() {
  Serial.begin(9600);
  pinMode(relayOut, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (!initialized) {
    initialized = true;
    interval = turnOn();
    previousMillis = currentMillis;
  }

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (on) {
      interval = turnOff();
    } else {
      interval = turnOn();
    }
  }
  
  delay(1000);
}

unsigned long turnOn() {
  on = true;
  digitalWrite(relayOut, LOW);
  return timeOn;
}

unsigned long turnOff() {
  on = false;
  digitalWrite(relayOut, HIGH);
  return timeOff;
}