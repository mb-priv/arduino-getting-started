int led_pin = 13;


void setup() {
    pinMode(led_pin, OUTPUT);

}

void loop() {
   analogWrite(led_pin, HIGH);
   delay(1000);
   analogWrite(led_pin, LOW);
   delay(1000);
}
