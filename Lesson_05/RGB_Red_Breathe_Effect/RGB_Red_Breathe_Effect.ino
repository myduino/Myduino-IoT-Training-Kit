int red = 9;

void setup() {
  pinMode (red, OUTPUT);

}

void loop() {
  for (int i=0;i<40; i++){
    analogWrite (red,i);
    delay (50);
    }

  for (int i=40     ;i>0; i--){
    analogWrite (red,i);
    delay (50);
    }
}
