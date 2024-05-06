#include <SoftwareSerial.h>  // Include the SoftwareSerial library

SoftwareSerial HC12(10, 11);  // HC12 using pins 10 (RX) and 11 (TX)

void setup() {
  Serial.begin(9600);  // Initialize the Serial Communication with the PC
  HC12.begin(9600);    // Initialize the HC12 Module Serial Communication

  pinMode(13, OUTPUT);
}

void loop() {
  // Read data from HC12 transmitter and print the sensors data
  if (HC12.available()) {
    
    String data = HC12.readString();

    int commaIndex = data.indexOf(",");
    
    String temperature = data.substring(0, commaIndex);
    String humidity = data.substring(commaIndex+1);
    
    Serial.println("=== Received Sensors Reading ===");
    Serial.println("Temperature: " + temperature + " °C");
    Serial.println("Humidity: " + humidity + " %RH");
  }
}
