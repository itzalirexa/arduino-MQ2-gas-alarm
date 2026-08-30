// Pin Definitions
const int GAS_SENSOR_PIN = A0;
const int BUZZER_PIN     = 8;

// Threshold & Configuration
const int GAS_THRESHOLD  = 400; // Adjust based on calibration

void setup() {
  pinMode(GAS_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("MQ-2 Gas Leakage Detector Initialized.");
}

void loop() {
  int gasLevel = analogRead(GAS_SENSOR_PIN);

  Serial.print("Gas Level: ");
  Serial.println(gasLevel);

  // Trigger alert if threshold exceeded
  if (gasLevel > GAS_THRESHOLD) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(200); // Sampling interval
}