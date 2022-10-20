#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
} 
void loop() {
  lcd.print("Anton ");
  delay(500);
  lcd.clear();
  delay(250);
  lcd.setCursor(6, 0);
  lcd.print("mali ");
  delay(500);
  lcd.clear();
  delay(250);
  lcd.setCursor(11, 0);
  lcd.print("kid!");
  delay(500);
  lcd.clear();
  delay(250);
  lcd.setCursor(3, 1);
  lcd.print("Vjeko bog!");
  delay(500);
  lcd.clear();
  delay(250);
}
      
