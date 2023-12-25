#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

const int pinRed = 21;
const int pinBlue = 19;
const int pinGreen = 18;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32Napat"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");

  // Set pin modes
  pinMode(pinRed, OUTPUT);
  pinMode(pinBlue, OUTPUT);
  pinMode(pinGreen, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char incomingChar = Serial.read();
    SerialBT.write(incomingChar);
    processCommand(incomingChar);
  }
  if (SerialBT.available()) {
    char incomingChar = SerialBT.read();
    Serial.write(incomingChar);
    processCommand(incomingChar);
  }
  delay(20);
}

void processCommand(char command) {
  switch (command) {
    case 'r':  // Red on
      digitalWrite(pinRed, HIGH);
      digitalWrite(pinBlue, LOW);
      digitalWrite(pinGreen, LOW);
      break;
    case 'y':  // Yellow on
      digitalWrite(pinRed, HIGH);
      digitalWrite(pinBlue, HIGH);
      digitalWrite(pinGreen, LOW);
      
      break;
    case 'g':  // Green on
      digitalWrite(pinRed, LOW);
      digitalWrite(pinBlue, LOW);
      digitalWrite(pinGreen, HIGH);
      break;
    case 'a':  // All on
      digitalWrite(pinRed, HIGH);
      digitalWrite(pinBlue, HIGH);
      digitalWrite(pinGreen, HIGH);
      break;
    case 'f':  // All off
      digitalWrite(pinRed, LOW);
      digitalWrite(pinBlue, LOW);
      digitalWrite(pinGreen, LOW);
      break;
    default:
      // Do nothing for unrecognized commands
      break;
  }
}
