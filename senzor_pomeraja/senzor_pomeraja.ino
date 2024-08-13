const int dioda = 2;
const int senzor = 7;

void setup() {
  pinMode(dioda, OUTPUT);
  pinMode(senzor, INPUT);

  Serial.begin(9600);
}

void loop() {
  // LOW ili HIGH
  int vrednost = digitalRead(senzor);
  Serial.println("Procitana vrednost: " + String(vrednost));

  if (vrednost == HIGH) {
    digitalWrite(dioda, HIGH);
    delay(200);
  } else {
    digitalWrite(dioda, LOW);
  }
}
