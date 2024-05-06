#include <SoftwareSerial.h>  // Include the SoftwareSerial library

SoftwareSerial HC12(10, 11);  // HC12 using pins 10 (RX) and 11 (TX)

void setup() {
  Serial.begin(9600);  // Initialize the Serial Communication with the PC
  HC12.begin(9600);    // Initialize the HC12 Module Serial Communication

  pinMode(13, OUTPUT);
}

void loop() {
  // Read data from HC12 transmitter and control the LED
  if (HC12.available()) {
    
    String data = HC12.readString();

    if (data == "ON") {
      digitalWrite(13, HIGH);
    }
    else if(data == "OFF") {
      digitalWrite(13, LOW);
    }
    
    Serial.println(data);
  }
}
