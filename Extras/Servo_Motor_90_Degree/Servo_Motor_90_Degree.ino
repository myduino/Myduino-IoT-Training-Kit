#include <Servo.h>

// Create a Servo object
Servo myServo;

// Define the pin where the servo signal wire is connected
const int servoPin = 9;  // Change this to the actual pin number

void setup() {
  myServo.attach(servoPin);  // Attach the servo to the specified pin
  myServo.write(90);         // Move the servo to 90 degrees
}

void loop() {
  
}
