#include <analogWrite.h>

int LED[]= {17 ,2 ,15 ,12};

void setup() {
  pinMode(LED[0], OUTPUT);
  pinMode(LED[1], OUTPUT);
  pinMode(LED[2], OUTPUT);
  pinMode(LED[3], OUTPUT);
  digitalWrite(LED[0] , HIGH);
  digitalWrite(LED[1] , HIGH);
  digitalWrite(LED[2] , HIGH);
  digitalWrite(LED[3] , HIGH);

}

void loop() {
  for(int x = 255 ; x >= 0 ; x--){
    analogWrite(LED[0] , x);
    delay(3);
  }
  for(int x = 0 ; x <= 255 ; x++){
    analogWrite(LED[0] , x);
    delay(3);
  }
   
  
}
