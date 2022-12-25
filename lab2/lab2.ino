int led1 = 12;
int led2 = 15;
int led3 = 2;
int led4 = 17;
void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
 }

void loop() {
  digitalWrite(led1,HIGH);
  delay(500);
  digitalWrite(led1,LOW);
  
  digitalWrite(led2,HIGH);
  delay(500);
  digitalWrite(led2,LOW);
  
  digitalWrite(led3,HIGH);
  delay(500);
  digitalWrite(led3,LOW);
  
  digitalWrite(led4,HIGH);
  delay(500);
  digitalWrite(led4,LOW);
  delay(1000);
 

}
