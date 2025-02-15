// Pin Definitions
const int ldrPin = A0;       // LDR connected to A0
const int pirPin = 2;        // PIR sensor connected to D2
const int ledPin1 = 9;        // LED connected to D9 (PWM for brightness control)
const int ledPin2 = 8;

// Variables
int ambientLight = 0;        // Stores LDR reading
int motionDetected = 0;      // Stores PIR state
int motionCount = 0;         // Counter for motion detections
int x = 0;

void setup() {
  pinMode(ldrPin, INPUT);    // LDR as input
  pinMode(pirPin, INPUT);    // PIR as input
  pinMode(ledPin1, OUTPUT);   // LED as output
  pinMode(ledPin2,OUTPUT);
  Serial.begin(9600);        // Start serial communication
  Serial.println("LDR and PIR Sensor Test");
 int x = 0;
}

void loop() {
  // Read ambient light level (0 = dark, 1023 = bright)
  ambientLight = analogRead(ldrPin);
  //Serial.print("Ambient Light: ");
  Serial.println(ambientLight);

  // Read PIR sensor (HIGH = motion detected, LOW = no motion)
  motionDetected = digitalRead(pirPin);
  //Serial.print("Motion: ");
  //Serial.println(motionDetected);

  // Check if both conditions are met: dark and motion detected
  if (ambientLight < 500 && motionDetected == HIGH) { // Adjust 500 as needed
    // Turn on the LED
    digitalWrite(ledPin1, HIGH);
  
    if (ambientLight < 300){
    digitalWrite(ledPin2, HIGH);
    }

    // Increment motion count
    motionCount++;
    //Serial.print("Motion count: ");
    //Serial.println(motionCount);
  } else {
    // Turn off the LED
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
  }

  // Small delay for stability
  delay(100);
}