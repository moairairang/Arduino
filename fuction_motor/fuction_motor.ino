int bt = 17;
int wifi = 2;
int ntp = 15;
int iot = 12;

void setup() {
  pinMode(bt , OUTPUT);
  pinMode(wifi , OUTPUT);
  pinMode(ntp , OUTPUT);
  pinMode(iot , OUTPUT);
  digitalWrite(bt , HIGH);
  digitalWrite(wifi , HIGH);
  digitalWrite(ntp , HIGH);
  digitalWrite(iot , HIGH);
}
void loop() {
  stoop();
  delay(500);
  forward();
  delay(500);
  backward();
  delay(500);
  left();
  delay(500);
  right();
  delay(500);
  stoop();
  delay(500);
  
}

void stoop(void){
  digitalWrite(bt , HIGH);
  digitalWrite(wifi , HIGH);
  digitalWrite(ntp , HIGH);
  digitalWrite(iot , HIGH);
}
void forward(void){
  digitalWrite(bt , LOW);
  digitalWrite(wifi , HIGH);
  digitalWrite(ntp , LOW);
  digitalWrite(iot , HIGH);
}
void backward(void){
  digitalWrite(bt , HIGH);
  digitalWrite(wifi , LOW);
  digitalWrite(ntp , HIGH);
  digitalWrite(iot , LOW);
}
void left(void){
  digitalWrite(bt , HIGH);
  digitalWrite(wifi , LOW);
  digitalWrite(ntp , LOW);
  digitalWrite(iot , HIGH);
}
void right(void){
  digitalWrite(bt , LOW);
  digitalWrite(wifi , HIGH);
  digitalWrite(ntp , HIGH);
  digitalWrite(iot , LOW);
}
