#include <analogWrite.h>

int LDR = 36;
int LED[]= {17 ,2 ,15 ,12};
int light = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED[0], OUTPUT);
  pinMode(LED[1], OUTPUT);
  pinMode(LED[2], OUTPUT);
  pinMode(LED[3], OUTPUT);
  digitalWrite(LED[0] , HIGH);
  digitalWrite(LED[1] , HIGH);
  digitalWrite(LED[2] , HIGH);
  digitalWrite(LED[3] , HIGH);
  pinMode(LDR, INPUT_PULLUP);

}

void loop() {
  light = map(analogRead(36),0,1024,0,4);
  Serial.println(light);

  if(light == 0){
    digitalWrite(LED[0],LOW);
    digitalWrite(LED[1],LOW);
    digitalWrite(LED[2],LOW);
    digitalWrite(LED[3],LOW);
  }
  else if(light == 1){
    digitalWrite(LED[0],LOW);
    digitalWrite(LED[1],LOW);
    digitalWrite(LED[2],LOW);
    digitalWrite(LED[3],HIGH);
  }
  else if(light == 2){
    digitalWrite(LED[0],LOW);
    digitalWrite(LED[1],LOW);
    digitalWrite(LED[2],HIGH);
    digitalWrite(LED[3],HIGH);
  }
  else if(light == 3){
    digitalWrite(LED[0],LOW);
    digitalWrite(LED[1],HIGH);
    digitalWrite(LED[2],HIGH);
    digitalWrite(LED[3],HIGH);
  }
  else if(light == 4){
    digitalWrite(LED[0],HIGHค);
    digitalWrite(LED[1],HIGH);
    digitalWrite(LED[2],HIGH);
    digitalWrite(LED[3],HIGH);
  }

  

}
