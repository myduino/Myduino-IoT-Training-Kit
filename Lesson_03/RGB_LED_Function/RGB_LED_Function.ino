int red = 8;
int green = 9;
int blue = 10;

void setup() {
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);
}

void loop() {
    rgb(1, 0, 0, 100); // red colour
    rgb(0, 1, 0, 500); // green colour
    rgb(0, 0, 1, 1000); // blue colour
    rgb(1, 1, 0, 700); // yellow colour
    rgb(1, 0, 1, 100); // purple colour
    rgb(1, 1, 1, 300); // white colour

}

void rgb(int r, int g, int b, int timer){
    digitalWrite(red, r);
    digitalWrite(green, g);
    digitalWrite(blue, b);
    delay(timer);
}