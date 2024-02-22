#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);  // RX, TX

void setup() {
  Serial.begin(9600);    // Serial monitor communication
  BTSerial.begin(9600);  // Bluetooth module communication

  Serial.println("Enter strings or AT commands for HC-05.");
}

void loop() {
  // Check if data is available from Bluetooth module
  if (BTSerial.available()) {
    // Read a string until a newline character
    String receivedString = BTSerial.readStringUntil('\n');

    // Print the received string to the Serial monitor
    Serial.println("Received: " + receivedString);
  }

  // Check if data is available from Serial monitor
  if (Serial.available()) {
    // Read a string until a newline character
    String sendString = Serial.readStringUntil('\n');
    // Send the string to the Bluetooth module
    BTSerial.print(sendString);
  }
}
