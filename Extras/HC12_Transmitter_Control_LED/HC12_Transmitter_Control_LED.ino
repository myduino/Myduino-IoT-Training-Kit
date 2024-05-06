#include <SoftwareSerial.h>  // Include the SoftwareSerial library

SoftwareSerial HC12(10, 11);  // HC12 using pins 10 (RX) and 11 (TX)

void setup() {
  Serial.begin(9600);  // Initialize the Serial Communication with the PC
  HC12.begin(9600);    // Initialize the HC12 Module Serial Communication
}

void loop() {
  // Send command to the HC12 receiver
  HC12.print("ON");
  delay(1000);
  HC12.print("OFF");
  delay(1000);
}
