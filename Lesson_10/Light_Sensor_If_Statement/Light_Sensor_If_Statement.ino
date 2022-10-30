int LDR_Pin = A0;

void setup() {
   Serial.begin (9600);
   pinMode (2, OUTPUT);

}

void loop() {

   int LDRReading = analogRead (LDR_Pin);
   float Vout = LDRReading * 0.00488;
   Serial.println (Vout);
   delay (2500);

   if (Vout >1.0){
      digitalWrite (2, HIGH);
   }
   else{
      digitalWrite (2, LOW);
   }
}
