// Define the pin where the IR sensor is connected
const int irSensorPin = 2;  // Change this to the actual pin number

void setup() {
  Serial.begin(9600);           // Initialize serial communication for debugging
  pinMode(irSensorPin, INPUT);  // Set the IR sensor pin as an input
}

void loop() {
  // Read the state of the IR sensor
  int irSensorState = digitalRead(irSensorPin);

  // Print the sensor state to the Serial monitor
  Serial.println("IR Sensor State: " + String(irSensorState));

  // Check if an obstacle is detected
  if (irSensorState == HIGH) {
    Serial.println("Obstacle detected!");  // Print a message if an obstacle is detected
  }

  delay(500);  // Add a short delay for stability
}
