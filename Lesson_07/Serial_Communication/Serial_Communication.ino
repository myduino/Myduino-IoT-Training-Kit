int a = 31;
int b = 89;
int c = 25;

void setup() {
    Serial.begin(9600);

    Serial.println("Basic Mathematics: ");

    Serial.print("a = ");
    Serial.println(a);
    Serial.print("b = ");
    Serial.println(b);
    Serial.print("c = ");
    Serial.println(c);

    Serial.print(" a + b = ");
    Serial.println(a + b);

    Serial.print(" a * c = ");
    Serial.println(a * c);

    Serial.print(" c / b = ");
    Serial.println(c / b);

    Serial.print(" b - c = ");
    Serial.println(b - c);
}

void loop() {

}
