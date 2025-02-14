const int ldrPin = A0;  // LDR connected to analog pin A0
const int ledPin = 7;  // LED connected to digital pin 7
int ldrValue = 0;      // Variable to store the LDR value
int threshold = 500;   // Threshold value for light level

void setup() {
  pinMode(ledPin, OUTPUT);  // Set the LED pin as output
  Serial.begin(9600);       // Start serial communication for debugging
}

void loop() {
  ldrValue = analogRead(ldrPin);  // Read the LDR value
  Serial.println(ldrValue);       // Print the LDR value to the Serial Monitor

  if (ldrValue < threshold) {
    digitalWrite(ledPin, HIGH);  // Turn on the LED if light level is below threshold
  } else {
    digitalWrite(ledPin, LOW);   // Turn off the LED if light level is above threshold
  }

  delay(100);  // Small delay for stability
}