int LED[]= {17 ,2 ,15 ,12};
void setup() {
  Serial.begin(9600);
  pinMode(LED[0], OUTPUT);
  
  
  digitalWrite(LED[0] , HIGH);
  

  for(int x = 0; x <=3; x++){
    digitalWrite(LED[0] , LOW);
    delay(100);
    digitalWrite(LED[0] , HIGH);
    delay(100);
}

void loop() {
  
}
