#include <analogWrite.h>

int LDR = 36;
int iot = 12;
int light = 0;

void setup() {
  Serial.begin(9600);
  pinMode(iot, OUTPUT);
  pinMode(LDR, INPUT_PULLUP);

}

void loop() {
  light = map(analogRead(36),0,1024,0,255);
  Serial.println(light);

  analogWrite(iot , light);

}
