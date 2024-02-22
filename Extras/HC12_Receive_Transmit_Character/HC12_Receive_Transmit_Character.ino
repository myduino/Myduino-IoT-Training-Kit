#include <SoftwareSerial.h>  // Include the SoftwareSerial library

SoftwareSerial HC12(10, 11);  // HC12 using pins 10 (RX) and 11 (TX)

void setup() {
  Serial.begin(9600);  // Initialize the Serial Communication with the PC
  HC12.begin(9600);    // Initialize the HC12 Module Serial Communication
}

void loop() {
  // Read data from HC12 and send it to the serial monitor
  while (HC12.available()) {
    Serial.write(HC12.read());
  }

  // Read data from the serial monitor and send it to the HC12 module
  while (Serial.available()) {
    HC12.write(Serial.read());
  }
}
