// Define the analog pin where the Sharp IR sensor is connected
const int sharpIRPin = A0;  // Change this to the actual analog pin number

// Constants for distance calculation (values may vary based on your specific sensor)
const float m = 1080.0;  // Sensor calibration factor
const float b = 2.0;     // Sensor calibration factor

void setup() {
  Serial.begin(9600);  // Initialize serial communication for debugging
}

void loop() {
  // Read the analog voltage from the Sharp IR sensor
  int sensorValue = analogRead(sharpIRPin);

  // Convert the analog value to distance in centimeters
  float distanceCM = m / (sensorValue - b);

  // Print the distance to the Serial monitor
  Serial.print("Analog Value: ");
  Serial.print(sensorValue);
  Serial.print(", Distance: ");
  Serial.print(distanceCM);
  Serial.println(" cm");

  delay(500);  // Add a short delay for stability
}