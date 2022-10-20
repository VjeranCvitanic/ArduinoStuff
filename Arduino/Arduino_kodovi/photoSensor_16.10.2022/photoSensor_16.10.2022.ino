#define lightSensor A0
#include <LiquidCrystal.h>

#include <dht11.h>
#define DHT11PIN 10

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int LIGHT_SENSOR_PIN = A0; // Arduino pin connected to light sensor's  pin
const int LED_PIN_1        = 8;  // Arduino pin connected to LED's pin
const int LED_PIN_2        = 7;  // Arduino pin connected to LED's pin
const int LED_PIN_3        = 6;  // Arduino pin connected to LED's pin
const int ANALOG_THRESHOLD_3 = 1000;
const int ANALOG_THRESHOLD_2 = 800;
const int ANALOG_THRESHOLD_1 = 550;

dht11 DHT11;

// variables will change:
int analogValue;
int lightPercentage;
int chk;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN_1, OUTPUT); // set arduino pin to output mode
  pinMode(LED_PIN_1, OUTPUT); // set arduino pin to output mode
  pinMode(LED_PIN_1, OUTPUT); // set arduino pin to output mode

  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
}

void loop() {
  analogValue = analogRead(LIGHT_SENSOR_PIN); // read the input on analog pin
  lightPercentage = (analogValue / 10.24);

  chk = DHT11.read(DHT11PIN);

  //Serial.print("Humidity (%): ");
  //Serial.println((float)DHT11.humidity, 2);

  //Serial.print("Temperature (C): ");
  //Serial.println((float)DHT11.temperature, 2);

  //Serial.print("Analog reading: ");
  //Serial.print(analogValue);   // the raw analog reading
  //Serial.print("\n");

  lcd.print("Tem: ");
  lcd.print(DHT11.temperature);

  lcd.print(" Hum: ");
  lcd.print(DHT11.humidity);
  lcd.print("%");
  
  lcd.setCursor(0, 1);

  lcd.print("Light: ");

  lcd.print(lightPercentage);
  lcd.print("%");

  

  if(analogValue < ANALOG_THRESHOLD_1)
    {
    digitalWrite(LED_PIN_1, HIGH); // turn on LED
    digitalWrite(LED_PIN_2, HIGH); // turn on LED
    digitalWrite(LED_PIN_3, HIGH); // turn on LED
    }
  else if(analogValue < ANALOG_THRESHOLD_2)
    {
      digitalWrite(LED_PIN_1, HIGH); // turn on LED
      digitalWrite(LED_PIN_2, HIGH); // turn on LED
      digitalWrite(LED_PIN_3, LOW);  // turn off LED
    }
   else if(analogValue < ANALOG_THRESHOLD_3)
    {
      digitalWrite(LED_PIN_1, HIGH); // turn on LED
      digitalWrite(LED_PIN_2, LOW); // turn on LED
      digitalWrite(LED_PIN_3, LOW);  // turn off LED
    }

    else
    {
      digitalWrite(LED_PIN_1, LOW); // turn on LED
      digitalWrite(LED_PIN_2, LOW); // turn on LED
      digitalWrite(LED_PIN_3, LOW);  // turn off LED
    }

    delay(2500);
  lcd.clear();
  delay(5);
}
