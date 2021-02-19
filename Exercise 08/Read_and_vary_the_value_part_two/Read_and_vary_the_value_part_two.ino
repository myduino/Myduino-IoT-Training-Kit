
void setup() {
    Serial.begin (9600);
}

void loop() {
    float volts = analogRead (A0);
    volts = (volts * 0.00488);
    Serial.print ("Voltage :");
    Serial.println(volts);

    if (volts < 2.5){
      Serial.print ("Low Voltages!");
      }
      
    delay (100);
    
}
