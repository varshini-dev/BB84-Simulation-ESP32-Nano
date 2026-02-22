#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

String receivedData = "";

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Quantum Secure");
  lcd.setCursor(0, 1);
  lcd.print("Waiting...");
}
void loop() {
  while (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {  
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("STATUS:");
      lcd.setCursor(0, 1);
      lcd.print(receivedData);
      receivedData = " "; // Reset buffer
    }
    else {
      receivedData += c;
    }
  }
}
