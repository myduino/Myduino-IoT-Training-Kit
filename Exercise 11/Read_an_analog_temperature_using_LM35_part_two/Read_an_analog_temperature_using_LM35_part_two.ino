void setup() {
   analogReference (INTERNAL);
   Serial.begin (9600);

}

void loop() {
  
   int sensorValue = analogRead (A0);
   float temp = sensorValue * 0.107422;
   Serial.println(temp);
   delay (100);
}
