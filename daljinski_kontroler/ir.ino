#include <IRremote.hpp>

// Definišite pin za IR prijemnik
#define IR_RECEIVE_PIN 31

String get_pressed_button_name(int code) {
  switch (code) {
    case 69: return "1";
    case 70: return "2";
    case 71: return "3";
    case 68: return "4";
    case 64: return "5";
    case 67: return "6";
    case 7:  return "7";
    case 21: return "8";
    case 9:  return "9";
    case 22: return "*";
    case 25: return "0";
    case 13: return "#";
    case 24: return "UP";
    case 82: return "DOWN";
    case 8:  return "LEFT";
    case 90: return "RIGHT";
    case 28: return "OK";
    default: return "Unknown";
  }
}

void setup() {
  // Postavite serijsku komunikaciju za ispis na serijski monitor
  Serial.begin(9600);

  // Inicijalizujte IR prijemnik
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);
}

void loop() {
  // Proverite da li je primljen IR signal
  if (IrReceiver.decode()) {
    // Ispišite sirove podatke signala
    Serial.print("IR Raw Data: ");
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);

    // Ispišite primljeni IR kod na serijski monitor
    int code = IrReceiver.decodedIRData.command;
    String button_name = get_pressed_button_name(code);

    Serial.print("IR kod: ");
    Serial.print(code);
    Serial.print(" - Dugme: ");
    Serial.println(button_name);

    // Ponovno pokrenite IR prijemnik da biste primili sledeći signal
    IrReceiver.resume();
  }

  // Dodajte dodatno kašnjenje kako biste omogućili IR prijemniku više vremena za resetovanje
  delay(200);
}
