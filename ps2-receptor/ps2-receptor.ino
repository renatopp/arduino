#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// ----------------------------------------------------------------------------
// Types
// ----------------------------------------------------------------------------
struct JOY {
  byte lx;
  byte ly;
  byte rx;
  byte ry;
  byte buttons1 = 0b00000000;
  byte buttons2 = 0b00000000;
};

// ----------------------------------------------------------------------------
// Global variables
// ----------------------------------------------------------------------------
#define NF_CE_PIN 9
#define NF_CNS_PIN 10
#define NF_SCK_PIN 13
#define NF_MOSI_PIN 11
#define NF_MISO_PIN 12

RF24 radio(NF_CE_PIN, NF_CNS_PIN);
JOY joystick;

void setup() {
  Serial.begin(57600);
  radio.begin();
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_250KBPS);
  radio.openReadingPipe(1, 0xF0F0F0F0E1LL);
  radio.startListening();

  if (radio.available()) {
    Serial.println(F("Radio available"));
  } else {
    Serial.println(F("Radio NOT available"));
  }
}

void loop() {
  if (!radio.available()) return;

  radio.read(&joystick, sizeof(JOY));
  Serial.print("lx: ");
  Serial.print(joystick.lx);
  Serial.print(" ly: ");
  Serial.print(joystick.ly);
  Serial.print(" rx: ");
  Serial.print(joystick.rx);
  Serial.print(" ry: ");
  Serial.print(joystick.ry);
  Serial.print(" buttons1: ");
  Serial.print(joystick.buttons1, BIN);
  Serial.print(" buttons2: ");
  Serial.println(joystick.buttons2, BIN);
  delay(50);
}