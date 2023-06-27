#include <Servo.h>
Servo myservo; //ประกาศตัวแปรแทน Servo
void setup()
{  
  Serial.begin(9600);
  myservo.attach(9); // กำหนดขา 9 ควบคุม Servo
  pinMode(A0,INPUT);
}
void loop() {
  int val = analogRead(A0);
  int va = map(val,0,1023,0,180);
  Serial.println(va);
  myservo.write(va);

  
  
  

}
