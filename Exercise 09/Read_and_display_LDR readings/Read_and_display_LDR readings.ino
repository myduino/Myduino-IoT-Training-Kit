int LDR_Pin = A0;

void setup() {
    Serial.begin (9600);
}

void loop() {
    int LDRReading = analogRead (LDR_Pin);
    //Read Pin A0 = Dout
    float Vout = LDRReading*0.00488;
    //coonverts reading to Voltage

    Serial.println (Vout);
    delay (250);
    //just share to slow dowsn the output for easier reading
}
