/*
  HTTM-Series-Touch-Switch  
  made on 21 oct 2020
  by Amir Mohammad Shojaee @ Electropeak
  Home

*/
const int SENSOR_PIN = 7; 

// Variables will change:
int lastState =LOW;      
int currentState;
         
void setup() {
  
  Serial.begin(9600);
  // initialize the Arduino's pin as aninput
  pinMode(SENSOR_PIN, INPUT);
}

void loop() {
  // read the state of the the input pin:
  currentState = digitalRead(SENSOR_PIN);

  if(lastState == LOW && currentState == HIGH)
    Serial.println("Sensor is ON");
  if(lastState == HIGH && currentState == LOW)
    Serial.println("Sensor is OFF");
  // save the the last state
  lastState = currentState;
}

