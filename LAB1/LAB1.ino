void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A5,INPUT);
  pinMode(A6,INPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(6,OUTPUT);
  
  
}
void loop() {
//  digitalWrite(6,HIGH);
//  delay(1000);
//  digitalWrite(6,LOW);
//  delay(1000);


//  RGB(255,255,255);
//  delay(1000);
//  RGB(255,0,0);
//  delay(1000);
//  RGB(0,255,0);
//  delay(1000);
//  RGB(0,0,255);
//  delay(1000);
//  RGB(255,255,0);
//  delay(100);
//  RGB(0,255,255);
//  delay(1000);

  int VAR1 = analogRead(A0);
  int Vout1 = map(analogRead(A0),0,1024,0,255);
  int VAR2 = analogRead(A5);
  int Vout2 = map(analogRead(A5),0,1024,0,255);
  int VAR3 = analogRead(A6);
  int Vout3 = map(analogRead(A6),0,1024,0,255);
  Serial.print(String(Vout1) + "\t" + String(Vout2)+ "\t" + String(Vout3));
  Serial.println();
  
  
  RGB(Vout1,Vout2,Vout3);

}

void RGB(int R, int G, int B){
  analogWrite(A3,R);
  analogWrite(A2,G);
  analogWrite(A1,B);
}
