// Pin Definitions
const int pirPin = 2;  // PIR sensor output connected to D2
const int ledPin = 13; // Built-in LED (optional, for visual feedback)

// Variables
int motionState = LOW;      // Stores the current state of motion (LOW = no motion, HIGH = motion detected)
int motionCount = 0;        // Counter for how many times motion has been detected

void setup() {
  pinMode(pirPin, INPUT);   // Set PIR pin as input
  pinMode(ledPin, OUTPUT);  // Set LED pin as output (optional)
  Serial.begin(9600);       // Start serial communication
  Serial.println("PIR Motion Sensor Test with Counter");
}

void loop() {
  // Read the PIR sensor state
  int motionDetected = digitalRead(pirPin);

  // Check if motion is detected
  if (motionDetected == HIGH) {
    if (motionState == LOW) {
      // Motion just detected
      Serial.println("Motion detected!");
      motionState = HIGH; // Update motion state
      digitalWrite(ledPin, HIGH); // Turn on LED (optional)

      // Increment the motion counter
      motionCount++;
      Serial.print("Motion count: ");
      Serial.println(motionCount);
    }
  } else {
    if (motionState == HIGH) {
      // Motion just stopped
      Serial.println("Motion stopped.");
      motionState = LOW; // Update motion state
      digitalWrite(ledPin, LOW); // Turn off LED (optional)
    }
  }

  // Small delay for stability
  delay(100);
}