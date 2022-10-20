#define lightSensor A0
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(11, OUTPUT);
  lcd.setCursor(0, 0);
}

void loop() {
  lcd.print("Svjetlost:");
  lcd.setCursor(11, 0);
  int lightLevel = analogRead(lightSensor);
  lcd.print(lightLevel);
  lcd.setCursor(0, 1);
  if(lightLevel <5){digitalWrite(11,HIGH);lcd.print("H");}
  else {digitalWrite(11,LOW);lcd.print("L");}
  Serial.println(lightLevel);
  delay(500);
  lcd.clear();
  delay(5);
}
