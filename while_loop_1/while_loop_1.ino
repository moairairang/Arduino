int led1 = 12;
int led2 = 15;
void setup() {
  pinMode(led1 , OUTPUT);
  pinMode(led2 , OUTPUT);
  digitalWrite(led1 , HIGH);

}

void loop() {
  int x=10;
  while(x >= 1){
    digitalWrite(led1 , LOW);
    delay(250);
    digitalWrite(led1 , HIGH);
    delay(250);
    x--;
  }

}
