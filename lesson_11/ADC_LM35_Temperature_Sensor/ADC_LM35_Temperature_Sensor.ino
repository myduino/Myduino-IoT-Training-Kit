void setup() {
   Serial.begin (9600);

}

void loop() {

   int Dout = analogRead (A0);
   float Vin = (Dout * 0.00488);
   float temp = Vin * 100;
   Serial.println(temp);
   delay (100);
}
