int led1 = 12;
int led2 = 15;
int led3 = 2;
int led4 = 17;

void setup() {
  pinMode(led1 , OUTPUT);
  pinMode(led2 , OUTPUT);
  pinMode(led3 , OUTPUT);
  pinMode(led4 , OUTPUT);
  digitalWrite(led1 , HIGH);
  digitalWrite(led2 , HIGH);
  digitalWrite(led3 , HIGH);
  digitalWrite(led4 , HIGH);

}

void loop() {
  bling(50);

}

void bling(int val){
  digitalWrite(led1 , LOW);
  delay(val);
  digitalWrite(led1 , HIGH);
  delay(val);
   
}
