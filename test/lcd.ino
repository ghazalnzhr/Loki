// Motor x LCD I2C

#include <LiquidCrystal_I2C.h> // Library for LCD
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x3F, 16, 2);

// Motor A connections
#define in1 3
#define in2 6
// Motor B connections
#define in3 10
#define in4 11

void setup() {
    Serial.begin(9600);
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

    // LCD
    lcd.init();
    lcd.backlight();
}

void loop() {
    motorTest();
    delay(1000);
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

void motorTest() {

    // 0 -> 255 and then 0 -> -255 between a delay()
    // For PWM maximum possible values are 0 to 255
    // Accelerate from zero to maximum speed
    for (int i = 0; i < 256; i++) {
        motor(i, i);
    }
    delay(30);

    for (int i = 0; i > -256; i--) {
        motor(i, i);
    }
<<<<<<< HEAD
}
=======
}
>>>>>>> 2fac59fe55fe1937078e17b6a83cf4b7fc0da392
