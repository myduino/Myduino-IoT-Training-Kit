int red = 8;
int green = 9;
int blue = 10;

void setup() {
    pinMode (red,OUTPUT);
    pinMode (green,OUTPUT);
    pinMode (blue,OUTPUT);
}

void loop() {
    digitalWrite (red,HIGH);
    digitalWrite (green, LOW);
    digitalWrite (blue, LOW);
    delay (1000);

    digitalWrite (red,LOW);
    digitalWrite (green, HIGH);
    digitalWrite (blue, LOW);
    delay (1000);

    digitalWrite (red,LOW);
    digitalWrite (green, LOW);
    digitalWrite (blue, HIGH);
    delay (1000);
}
