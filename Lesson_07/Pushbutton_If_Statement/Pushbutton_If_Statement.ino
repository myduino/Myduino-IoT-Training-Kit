void setup() {
    pinMode(9, INPUT);
    pinMode(5, OUTPUT);

}

void loop() {
  int pushbuttonStatus = digitalRead(9);
  if (pushbuttonStatus == HIGH){
    digitalWrite(5, HIGH);
  }
  else{
    digitalWrite(5, LOW);
  }
}
