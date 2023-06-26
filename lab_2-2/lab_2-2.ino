void setup() {
  Serial.begin(9600);
  pinMode(5,INPUT);

}

void loop() {
  int val = digitalRead(5);
  //Serial.println(val);
  if(val == 1){
    Serial.println("Hello world");
    delay(200);
  }
  else{
    Serial.println("Good bye");
    delay(200);
  }

}
