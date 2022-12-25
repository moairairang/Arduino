int s1 = 16;
int s2 = 14;
int led1 = 12;
int led2 = 15;
char key;


void setup(){
  pinMode(s1 , INPUT);
  pinMode(s2 , INPUT);
  pinMode(led1 , OUTPUT);
  pinMode(led2 , OUTPUT);
  Serial.begin(9600);
  digitalWrite(led1 , HIGH);
  digitalWrite(led2 , HIGH);
  
}
void loop(){
  key = Serial.read();
  Serial.println(key);
  delay(100);

  switch(key){
    case 'a': digitalWrite(led1 , LOW);
              digitalWrite(led2 , HIGH);
              Serial.println("IOT on");
              delay(5000);
              break;
    case 'b': digitalWrite(led1 , HIGH);
              digitalWrite(led2 , LOW);  
              Serial.println("NTP on"); 
              delay(5000);
              break;
    default:a
           digitalWrite(led1 , HIGH);
           digitalWrite(led2, HIGH);
           delay(5000);
  }
}

  
