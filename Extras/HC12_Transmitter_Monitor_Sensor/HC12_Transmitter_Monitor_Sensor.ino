#include <SoftwareSerial.h>  // Include the SoftwareSerial library
#include <SimpleDHT.h>

SoftwareSerial HC12(10, 11);  // HC12 using pins 10 (RX) and 11 (TX)
SimpleDHT11 dht11(2);

void setup() {
  Serial.begin(9600);  // Initialize the Serial Communication with the PC
  HC12.begin(9600);    // Initialize the HC12 Module Serial Communication
}

void loop() {

  // Read DHT11 samples data
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    return;
  }
  
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" °C, ");
  Serial.print((int)humidity); Serial.println(" %RH");

  // Send sensor data to the HC12 receiver
  HC12.print(String(temperature) + "," + String(humidity));
}
