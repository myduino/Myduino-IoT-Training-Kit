void setup() {
    pinMode (9, INPUT);
    pinMode (5, OUTPUT);

}

void loop() {
    if (digitalRead (9) == HIGH){
      digitalWrite (5,HIGH);
      }
    else{
      digitalWrite(5,LOW);
    }

}
