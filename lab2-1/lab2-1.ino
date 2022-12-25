int led1 = 17;
int led2 = 2;
int led3 = 15;
int led4 = 12;
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
