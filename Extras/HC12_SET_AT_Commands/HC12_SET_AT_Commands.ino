#include <SoftwareSerial.h>

// HC12 RX pin to Arduino pin 11
// HC12 TX pin to Arduino pin 10
SoftwareSerial HC12(10, 11);

void setup()  {
  // HC12 SET pin to Arduino Pin 9
  pinMode(9, OUTPUT);
  // HC12 SET LOW
  // Entering AT Command Mode
  digitalWrite(9, LOW);

  Serial.begin(9600);
  Serial.println("Enter AT commands:");

  HC12.begin(9600);
}

void loop() {

  // Keep reading from HC12 and send to Arduino Serial Monitor
  if (HC12.available())
    Serial.write(HC12.read());

  // Keep reading from Arduino Serial Monitor and send to HC12
  if (Serial.available())
    HC12.write(Serial.read());
}