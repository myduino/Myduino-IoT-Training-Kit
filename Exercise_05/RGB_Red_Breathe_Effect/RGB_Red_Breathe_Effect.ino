int red = 9;

void setup() {
  pinMode (red, OUTPUT);
}

void loop() {
  for (int brightness = 0; brightness < 40; brightness++){
    analogWrite(red, brightness);
    delay(50);
  }

  for (int brightness = 40; brightness > 0; brightness--){
    analogWrite(red, brightness);
    delay(50);
  }
}
