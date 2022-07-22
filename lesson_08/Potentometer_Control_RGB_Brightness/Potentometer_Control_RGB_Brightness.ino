
void setup() {
    pinMode (9, OUTPUT);
}

void loop() {
    int pot = analogRead (A0);
    pot = map(pot, 0, 1023, 0, 255);
    analogWrite (9, pot);
    
}
