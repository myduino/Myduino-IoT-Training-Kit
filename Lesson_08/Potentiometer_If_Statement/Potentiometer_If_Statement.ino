void setup() {
    Serial.begin(9600);
}

void loop() {
    int adc = analogRead(A0);
    float voltage = (adc * 0.00488);
    Serial.print("Voltage: ");
    Serial.println(voltage);

    if (voltage < 2.0){
      Serial.print ("Low voltage!");
    }
      
    delay(100);
}
