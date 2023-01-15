int bt = 17;
int wifi = 2;
int ntp = 15;
int iot = 12;
int s1 = 16;
int s2 = 14;

void setup() {
  pinMode(bt , OUTPUT);
  pinMode(wifi , OUTPUT);
  pinMode(ntp , OUTPUT);
  pinMode(iot , OUTPUT);
  pinMode(s1 , INPUT_PULLUP);
  pinMode(s2 , INPUT_PULLUP);
  digitalWrite(bt , HIGH);
  digitalWrite(wifi , HIGH);
  digitalWrite(ntp , HIGH);
  digitalWrite(iot , HIGH);
}

void loop(){
  int a = digitalRead(s1);
  int b = digitalRead(s2);
  
  if(a == LOW){
    forward();
  }
  else if(b == LOW){
    backward();
  }
  else{
    stoop();
  }
  
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

void stoop(void){
  digitalWrite(bt , HIGH);
  digitalWrite(wifi , HIGH);
  digitalWrite(ntp , HIGH);
  digitalWrite(iot , HIGH);
  
}
