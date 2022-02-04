// Using templates for accepting any datatype
template <typename T>
void lcdDisplay(int x, int y, T userInput) {
  lcd.setCursor(x, y);
  lcd.print(userInput);
}
