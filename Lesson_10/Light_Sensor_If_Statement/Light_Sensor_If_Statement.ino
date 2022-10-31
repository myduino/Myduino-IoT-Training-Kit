int LDR_Pin = A0;

void setup() {
   Serial.begin(9600);
   pinMode(2, OUTPUT);

}

void loop() {

   int adc = analogRead(LDR_Pin);
   float voltage = adc * 0.00488;
   Serial.println(voltage);
   delay (2500);

   if (voltage > 1.0){
      digitalWrite(2, HIGH);
   }
   else{
      digitalWrite(2, LOW);
   }
}
