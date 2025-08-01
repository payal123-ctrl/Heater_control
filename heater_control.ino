const int tempPin = A0;        // LM35 analog sensor
const int relayPin = 8;        // Relay connected to digital pin 8
float temperature = 0;

enum State { IDLE, HEATING, STABILIZING, TARGET_REACHED, OVERHEAT };
State currentState = IDLE;

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);  // Heater OFF initially

  Serial.begin(9600);
  Serial.println("Heater Control System Initialized");
}

void loop() {
  int analogValue = analogRead(tempPin);
  temperature = (analogValue * 5.0 / 1023.0) * 100.0; // Convert to °C (LM35)

  // State decision based on temperature
  if (temperature < 30) {
    currentState = HEATING;
    digitalWrite(relayPin, HIGH);  // Heater ON (LED ON)
  } else if (temperature >= 30 && temperature <= 40) {
    currentState = STABILIZING;
    digitalWrite(relayPin, HIGH);  // Heater ON (LED ON)
  } else if (temperature > 40 && temperature <= 45) {
    currentState = TARGET_REACHED;
    digitalWrite(relayPin, HIGH);   // Heater OFF (LED OFF)
  } else if (temperature > 45) {
    currentState = OVERHEAT;
    digitalWrite(relayPin, HIGH);   // Heater OFF (LED OFF)
  }

  // Logging
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C\tState: ");
  printState(currentState);

  delay(1000);  // 1s delay
}

void printState(State s) {
  switch(s) {
    case IDLE: Serial.println("IDLE"); break;
    case HEATING: Serial.println("HEATING"); break;
    case STABILIZING: Serial.println("STABILIZING"); break;
    case TARGET_REACHED: Serial.println("TARGET REACHED"); break;
    case OVERHEAT: Serial.println("OVERHEAT"); break;
  }
}
