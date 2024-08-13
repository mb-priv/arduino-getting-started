
const int led1_pin = 13;
const int led2_pin = 12;
const int led3_pin = 11;

const int sensor_trig_pin = 9;
const int sensor_echo_pin = 10;
float duration, distance;  

void setup() {
    pinMode(led1_pin, OUTPUT);
    pinMode(led2_pin, OUTPUT);
    pinMode(led3_pin, OUTPUT);

    pinMode(sensor_trig_pin, OUTPUT);  
  	pinMode(sensor_echo_pin, INPUT); 

    Serial.begin(9600);   
}

float get_distance_from_sensor()
{
    digitalWrite(sensor_trig_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(sensor_trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(sensor_trig_pin, LOW);

    duration = pulseIn(sensor_echo_pin, HIGH);
    distance = (duration * 0.0343)/2;

    return distance;
}

void loop() {
    distance = get_distance_from_sensor();

    Serial.print("Distance: ");
    Serial.println(distance);

    if (distance < 10) {
      digitalWrite(led1_pin, LOW);
      digitalWrite(led2_pin, LOW);
      digitalWrite(led3_pin, LOW);
      delay(100);
      digitalWrite(led1_pin, HIGH);
      digitalWrite(led2_pin, HIGH);
      digitalWrite(led3_pin, HIGH);
    }

    if (distance >= 10 && distance < 20) {
      digitalWrite(led1_pin, LOW);
      digitalWrite(led2_pin, LOW);
      digitalWrite(led3_pin, LOW);
      delay(100);
      digitalWrite(led1_pin, HIGH);
      digitalWrite(led2_pin, HIGH);
    }

    if (distance >= 20 && distance < 40) {
      digitalWrite(led1_pin, LOW);
      digitalWrite(led2_pin, LOW);
      digitalWrite(led3_pin, LOW);      
      delay(100);
      digitalWrite(led1_pin, HIGH);
    } 

    if (distance >= 40) {
      digitalWrite(led1_pin, LOW);
      digitalWrite(led2_pin, LOW);
      digitalWrite(led3_pin, LOW); 
    }

    delay(500);
}
