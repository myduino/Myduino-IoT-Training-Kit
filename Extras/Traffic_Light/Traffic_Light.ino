// Define the pins for the traffic light LEDs
const int redPin = 2;     // Change this to the actual pin number
const int yellowPin = 3;  // Change this to the actual pin number
const int greenPin = 4;   // Change this to the actual pin number

void setup() {
  pinMode(redPin, OUTPUT);     // Set the red LED pin as output
  pinMode(yellowPin, OUTPUT);  // Set the yellow LED pin as output
  pinMode(greenPin, OUTPUT);   // Set the green LED pin as output
}

void loop() {
  // Red light
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
  delay(5000);  // 5 seconds for red

  // Red and yellow lights
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, LOW);
  delay(2000);  // 2 seconds for red and yellow

  // Green light
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(5000);  // 5 seconds for green

  // Yellow light
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, LOW);
  delay(2000);  // 2 seconds for yellow
}
