#include <Servo.h>

// Create a Servo object
Servo myServo;

// Define the pin where the servo signal wire is connected
const int servoPin = 9;  // Change this to the actual pin number

void setup() {
  myServo.attach(servoPin);  // Attach the servo to the specified pin
}

void loop() {
  // Sweep the servo motor back and forth
  for (int angle = 0; angle <= 180; angle += 1) {
    myServo.write(angle);  // Set servo position
    delay(15);             // Delay for smooth movement
  }

  delay(1000);  // Pause at the end position

  for (int angle = 180; angle >= 0; angle -= 1) {
    myServo.write(angle);  // Set servo position
    delay(15);             // Delay for smooth movement
  }

  delay(1000);  // Pause at the start position
}
