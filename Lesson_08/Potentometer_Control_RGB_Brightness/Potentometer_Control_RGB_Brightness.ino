void setup() {
    pinMode(9, OUTPUT);
}

void loop() {
    int adc = analogRead(A0);
    int pwm = map(adc, 0, 1023, 0, 255);
    analogWrite(9, pwm);
    
}
