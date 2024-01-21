int LDR_Pin = A0;

void setup() {
    Serial.begin (9600);
}

void loop() {
    int adc = analogRead(LDR_Pin);
    //Read Pin A0 = Dout
    float voltage = adc * 0.00488;
    //coonverts reading to Voltage

    Serial.println(voltage);
    delay(250);
    //just share to slow dowsn the output for easier reading
}
