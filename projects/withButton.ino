// SRF x Motors
#define PIN_TRIG 4
#define PIN_ECHO 7
#define buttonPin 2

// Motor A connections
#define in1 3
#define in2 5
// Motor B connections
#define in3 6
#define in4 9

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f, 16, 2);

// Button variables
int buttonPushCounter = 0;
int buttonState;
int lastButtonState;

// Scale
const float scale = 10.0;

// Distance
float distanceToWall;
float currentDistance;

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(PIN_TRIG, OUTPUT);
  pinMode(PIN_ECHO, INPUT);

  // Set all the motor control pins to outputs

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  /* Start main program */
  // Give instructions to the user
  lcdDisplay(0, 0, "Please push the button");
  delay(1000);
  lcd.clear();

  // Get intructions from the user in the first 3 seconds
  do {
    buttonCounter();
    lcdDisplay(0, 0, buttonPushCounter);
  } while (millis() <= 4000);

  // calculate Initial Distance
  distanceToWall = 100.0 - (float(buttonPushCounter) * scale);
}

void loop() {
  while (readSrf() >= distanceToWall) {
    motor(100, 100);
  }
  // Turn off motors - Final state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

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

  lcdDisplay(0, 1, distance);
  return (distance);
  delay(1000);
}

void buttonCounter() {
  // read the state of the button
  int buttonState = digitalRead(buttonPin);

  Serial.println(buttonState);
  // Compare the previous state of the push button to its new state
  if (buttonState != lastButtonState) {
    // If the state has changed, increment the counter
    if (buttonState == 0) {
      // If the current state is HIGH, then the button went from off to on
      buttonPushCounter++;  // Increment
      Serial.println(buttonPushCounter);
    }  // Wait for 50 ms to avoid bouncing
    delay(50);
  }
  lastButtonState = buttonState;
}

//  This function lets you control speed and direction of the motors
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

/* LCD Utils */
void lcdDisplay(int x, int y, int userInput) {
  lcd.setCursor(x, y);
  lcd.print(userInput);
}
void lcdDisplay(int x, int y, float userInput) {
  lcd.setCursor(x, y);
  lcd.print(userInput);
}
void lcdDisplay(int x, int y, String userInput) {
  lcd.setCursor(x, y);
  lcd.print(userInput);
}
void lcdDisplay(int x, int y, char userInput) {
  lcd.setCursor(x, y);
  lcd.print(userInput);
}
void lcdDisplay(int x, int y, double userInput) {
  lcd.setCursor(x, y);
  lcd.print(userInput);
}
void lcdDisplay(int x, int y, long userInput) {
  lcd.setCursor(x, y);
  lcd.print(userInput);
}
void lcdDisplay(int x, int y, short userInput) {
  lcd.setCursor(x, y);
  lcd.print(userInput);
}