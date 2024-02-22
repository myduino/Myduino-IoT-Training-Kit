#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11);  // RX, TX

void setup() {
  Serial.begin(9600);    // Serial monitor communication
  BTSerial.begin(9600);  // Bluetooth module communication

  Serial.println("Enter AT commands for HC-05. Type 'AT' to check the connection.");
}

void loop() {
  // Check if data is available from Bluetooth module
  if (BTSerial.available()) {
    char c = BTSerial.read();  // Read the character

    // Print the character to the Serial monitor
    Serial.write(c);

    // If the character is a newline, print a new line in the Serial monitor
    if (c == '\n') {
      Serial.println();
    }
  }

  // Check if data is available from Serial monitor
  if (Serial.available()) {
    // Send the character to the Bluetooth module
    BTSerial.write(Serial.read());
  }
}