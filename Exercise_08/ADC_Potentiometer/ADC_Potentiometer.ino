void setup() {
    Serial.begin(9600);
}

void loop() {
    int adcValue = analogRead(A0);
    float voltage = (adcValue * 0.00488);
    Serial.print("Voltage: ");
    Serial.println(voltage);
    delay(100);
}
