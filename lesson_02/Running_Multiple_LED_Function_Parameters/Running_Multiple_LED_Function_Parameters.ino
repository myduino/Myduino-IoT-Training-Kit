void setup() {
    pinMode(13,OUTPUT);
    pinMode(12,OUTPUT);
    pinMode(11,OUTPUT);
    pinMode(10,OUTPUT);
}

void loop() {

    blinky(13, 1000);
    blinky(12, 1000);
    blinky(11, 1000);
    blinky(10, 1000);

}

void blinky(int pin,int timer) {

    digitalWrite(pin,HIGH);
    delay(timer);
    digitalWrite(pin, LOW);
    delay(timer);

}
