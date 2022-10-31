void setup() {
    pinMode(13, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
}

void loop() {
    blinky(13);
    blinky(12);
    blinky(11);
    blinky(10);
    blinky(11);
    blinky(12);
}

void blinky(int pin) {
    digitalWrite(pin, HIGH);
    delay(1000);
    digitalWrite(pin, LOW);
    delay(1000);
}
