void readSrf() {
  // Start a new measurement:
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  // Read the result:
  float duration = pulseIn(PIN_ECHO, HIGH);
  float distance = (duration / 2) * 0.0344;
  lcd.setCursor(0,0);
  lcd.print("Distance in CM: ");
  lcd.setCursor(0,1);
  lcd.print(distance);
  delay(1000);
}