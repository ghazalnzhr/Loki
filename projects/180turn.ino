// Arduino and SRF robot 2.0
// Description: Write the code for a robot that travels a distance, gets to 20
// cm distance from the wall and takes a 180 degree turn
// Then, goes back to exactly where it was before

// Motor conncetions
#define in1 3
#define in2 5
#define in3 6
#define in4 9

// SRF Conncetions
#define PIN_TRIG 4
#define PIN_ECHO 7

// LCD connections
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);

// Variables
float initialDistance;
const float lengthOfRobot = 15.5;
bool firstTime = true;
unsigned long deltaTime = 0;
unsigned long firstDelta = 0;

void setup() {
  // Serial communication
  Serial.begin(9600);

  // Motors
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // SRF
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  // LCD
  lcd.init();
  lcd.backlight();

  // Read initial distance
  initialDistance = readSrf();
}

void loop() {
  float distance = readSrf();
  lcdDisplay(0, 1, distance);
  if (millis() - deltaTime >= deltaTime && deltaTime != firstDelta) {
    // if it's already turned around and now is in its origin
    turnOffMotors();
  } else if (distance >= 20.0) {
    // Now go to the front
    motor(50, 60);
  } else if (distance < 20.0) {  // Turn backwards
    deltaTime = millis();
    motor(60, -60);
    delay(1800);
  }
}

// Motor functions
void motor(int left, int right) {
  if (left >= 0) {
    analogWrite(in1, left);
    digitalWrite(in2, LOW);
  } else {
    digitalWrite(in1, LOW);
    analogWrite(in2, abs(left));
  }

  if (right >= 0) {
    analogWrite(in3, right);
    digitalWrite(in4, LOW);
  } else {
    digitalWrite(in3, LOW);
    analogWrite(in4, abs(right));
  }
}
void turnOffMotors() {
  // Utility function for turning off all the motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

// SRF functions
float readSrf() {
  // Start a new measurement:
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  // Read the result:
  float duration = pulseIn(PIN_ECHO, HIGH);
  float distance = (duration / 2) * 0.0344;
  return (distance);
  delay(1000);
}

// LCD functions
template <typename T>
void lcdDisplay(int x, int y, T genericInput) {
  lcd.setCursor(x, y);
  lcd.print(genericInput);
}