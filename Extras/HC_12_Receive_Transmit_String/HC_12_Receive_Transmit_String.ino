#include <SoftwareSerial.h>

SoftwareSerial HC12(10, 11);

void setup() {
  Serial.begin(9600);
  HC12.begin(9600);
}

void loop() {
  // Initialize an empty string to store the received characters
  String receivedString = "";  

  // Read characters until a newline character is encountered
  while (HC12.available()) {
    char c = HC12.read();
    if (c == '\n') {
      // End of the string, do something with the received string
      Serial.println("Received: " + receivedString);
      receivedString = "";  // Clear the string for the next data
    } else {
      receivedString += c;  // Concatenate the character to the string
    }
  }

  // Send a string from Serial monitor to HC12
  if (Serial.available()) {
    // Read a string until a newline character
    String sendString = Serial.readStringUntil('\n');
    HC12.print(sendString);  // Send the string to HC12
  }
}
