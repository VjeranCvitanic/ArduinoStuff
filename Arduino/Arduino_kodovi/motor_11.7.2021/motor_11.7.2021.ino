#define pwm 3

void setup() {
  // put your setup code here, to run once:
  pinMode(pwm,OUTPUT);
  digitalWrite(pwm,LOW);

}

void loop() {
  digitalWrite(pwm,HIGH);
  delay(500);
  digitalWrite(pwm,LOW);
  delay(500);
}
