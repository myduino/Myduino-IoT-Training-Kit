int red = 9;

void setup() {
  pinMode(red, OUTPUT);
}

void loop() {
  analogWrite(red,0);
  delay(1000);

  analogWrite(red,10);
  delay(1000);

  analogWrite(red,20);
  delay(1000);

  analogWrite(red,30);
  delay(1000);

  analogWrite(red,40);
  delay(1000);

}
