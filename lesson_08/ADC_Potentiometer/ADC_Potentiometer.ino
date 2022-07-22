
void setup() {
    Serial.begin (9600);
}

void loop() {
    int Dout = analogRead (A0);
    float Vin = (Dout * 0.00488);
    Serial.print ("Voltage :");
    Serial.println(Vin);
    delay (100);
}
