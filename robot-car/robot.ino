const int SONAR_TRIG = 8;
const int SONAR_ECHO = 9;
const int MOTOR_IN1 = 2;
const int MOTOR_IN2 = 3;
const int MOTOR_IN3 = 4;
const int MOTOR_IN4 = 5;
const int MOTOR_ENA = 11;
const int MOTOR_ENB = 10;

const int LEFT_SPEED = MOTOR_ENA;
const int LEFT_FORWARD = MOTOR_IN1;
const int LEFT_BACKWORD = MOTOR_IN2;
const int RIGHT_FORWARD = MOTOR_IN3;
const int RIGHT_BACKWORD = MOTOR_IN4;
const int RIGHT_SPEED = MOTOR_ENB;


void setup() {
  Serial.begin(115200);

  pinMode(SONAR_ECHO, INPUT);
  pinMode(SONAR_TRIG, OUTPUT);
  pinMode(LEFT_SPEED, OUTPUT);
  pinMode(LEFT_FORWARD, OUTPUT);
  pinMode(LEFT_BACKWORD, OUTPUT);
  pinMode(RIGHT_FORWARD, OUTPUT);
  pinMode(RIGHT_BACKWORD, OUTPUT);
  pinMode(RIGHT_SPEED, OUTPUT);
}

void loop() {
  digitalWrite(SONAR_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(SONAR_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(SONAR_TRIG, LOW);
  long duration = pulseIn(SONAR_ECHO, HIGH);
  int distance = duration * 0.034 / 2;
  Serial.print(" Sonar: ");
  Serial.println(distance);
  delay(1000);

  digitalWrite(LEFT_FORWARD, HIGH);
  digitalWrite(LEFT_BACKWORD, LOW);
  analogWrite(LEFT_SPEED, 128);
}

