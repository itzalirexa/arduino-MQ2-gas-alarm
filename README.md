# Arduino MQ-2 Gas Leakage Detection & Alarm System

A real-time embedded hardware project built with Arduino UNO and an MQ-2 gas sensor to monitor ambient gas/smoke concentration levels and trigger an audible buzzer alarm when thresholds are exceeded.

---

## 🛠️ Hardware Components

* **Microcontroller:** Arduino UNO
* **Sensor:** MQ-2 Gas & Smoke Sensor Module
* **Actuator:** Active 5V Buzzer
* **Simulation Tool:** Proteus Design Suite

---

## 📐 Circuit Schematic

Below is the circuit design and schematic simulation created in **Proteus**:

![MQ-2 Gas Alarm Proteus Schematic](schematic.png)

### Pin Mapping

| Component | Arduino Pin | Description |
| :--- | :--- | :--- |
| **MQ-2 Sensor (AO)** | `A0` | Analog input for gas concentration measurement |
| **MQ-2 Sensor (VCC)** | `5V` | 5V Power Supply |
| **MQ-2 Sensor (GND)** | `GND` | Ground |
| **Buzzer (+)** | `Pin 8` | Digital output control for sound alarm |
| **Buzzer (-)** | `GND` | Ground |

---

## 💻 Code Structure

```cpp
// Pin Definitions
const int GAS_SENSOR_PIN = A0;
const int BUZZER_PIN     = 8;

// Threshold configuration (calibrate based on environment)
const int GAS_THRESHOLD  = 400; 

void setup() {
  pinMode(GAS_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("MQ-2 Gas Detector System Initialized.");
}

void loop() {
  int gasLevel = analogRead(GAS_SENSOR_PIN);

  Serial.print("Gas Level: ");
  Serial.println(gasLevel);

  // Trigger alarm if gas level exceeds safety threshold
  if (gasLevel > GAS_THRESHOLD) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  delay(200);
}
🚀 Getting Started
Open GasAlarm.ino in the Arduino IDE.

Connect your Arduino UNO via USB.

Select board Arduino UNO and the matching COM Port.

Click Upload.

Open Serial Monitor at 9600 baud to observe real-time gas level readings.

👤 Author: Alireza

🔗 GitHub: github.com/itzalirexa
