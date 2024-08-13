#include <IRremote.hpp>

#define IR_RECEIVE_PIN 8

const int LED1_PIN = 5;
const int LED2_PIN = 4;
const int LED3_PIN = 3;
const int LED4_PIN = 2;

int brightness = 20;
const int MIN_BRIGHTNESS = 0;
const int MAX_BRIGHTNESS = 255;
const int BRIGHTNESS_STEP = 10;

bool led1_working = false;
bool led2_working = false;
bool led3_working = false;
bool led4_working = false;

String get_pressed_button_name(int code) {
  switch (code) {
    case 69: return "1";
    case 70: return "2";
    case 71: return "3";
    case 68: return "4";
    case 64: return "5";
    case 67: return "6";
    case 7: return "7";
    case 21: return "8";
    case 9: return "9";
    case 22: return "*";
    case 25: return "0";
    case 13: return "#";
    case 24: return "UP";
    case 82: return "DOWN";
    case 8: return "LEFT";
    case 90: return "RIGHT";
    case 28: return "OK";
    default: return "";
  }
}

void setup() {
  // Setup LEDs
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);

  // Setup IR controller
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Start the receiver

  // Setup Serial (console logging)
  Serial.begin(9600);
}

void updateLEDs() {
  if (led1_working) {
    analogWrite(LED1_PIN, brightness);
  } else {
    digitalWrite(LED1_PIN, LOW);
  }

  if (led2_working) {
    analogWrite(LED2_PIN, brightness);
  } else {
    digitalWrite(LED2_PIN, LOW);
  }

  if (led3_working) {
    analogWrite(LED3_PIN, brightness);
  } else {
    digitalWrite(LED3_PIN, LOW);
  }

  if (led4_working) {
    analogWrite(LED4_PIN, brightness);
  } else {
    digitalWrite(LED4_PIN, LOW);
  }
}

String get_pressed_button() {
  int pressed_button_code = IrReceiver.decodedIRData.command;

  String pressed_button_name = get_pressed_button_name(pressed_button_code);

  Serial.println("Pressed button raw: " + String(pressed_button_code) + " Pressed button: " + pressed_button_name);

  delay(100);

  IrReceiver.resume();

  return pressed_button_name;
}

void handle_pressed_button(String pressed_button) {
  if (pressed_button == "1") {
    led1_working = !led1_working;

  } else if (pressed_button == "2") {
    led2_working = !led2_working;

  } else if (pressed_button == "3") {
    led3_working = !led3_working;

  } else if (pressed_button == "4") {
    led4_working = !led4_working;

  } else if (pressed_button == "LEFT") {
    if ((brightness - BRIGHTNESS_STEP) >= MIN_BRIGHTNESS) {
      brightness -= BRIGHTNESS_STEP;
    }
    Serial.println("Brightness decreased: " + String(brightness));

  } else if (pressed_button == "RIGHT") {
    if ((brightness + BRIGHTNESS_STEP) <= MAX_BRIGHTNESS) {
      brightness += BRIGHTNESS_STEP;
    }
    Serial.println("Brightness increased: " + String(brightness));
  }
}

void loop() {
  if (IrReceiver.decode()) {
    // read pressed button
    String pressed_button_name = get_pressed_button();

    // do a propriate action for pressed button
    handle_pressed_button(pressed_button_name);

    // Update LED states according to pressed buttons
    updateLEDs();
  }
}
