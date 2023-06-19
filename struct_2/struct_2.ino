struct LED{
  String name;
  int L[]= {12 ,15 ,2 ,17};
  
};

struct LED led1;


void setup() {
  Serial.begin(9600);
  pinMode(led1.L[0],OUTPUT);
  pinMode(led1.L[1],OUTPUT);
  pinMode(led1.L[2],OUTPUT);
  pinMode(led1.L[3],OUTPUT);
  digitalWrite(led1.L[0],HIGH);
  digitalWrite(led1.L[1],HIGH);
  digitalWrite(led1.L[2],HIGH);
  digitalWrite(led1.L[3],HIGH);
  led1.name = "DesignByChobram";

}

void loop() {
  Serial.println("HELLO "+led1.name);
  for(int i = 0; i <4 ; i++){
    digitalWrite(led1.L[i] , LOW);
    delay(100);
    
}
for(int i = 0; i <4 ; i++){
    digitalWrite(led1.L[i] ,HIGH);
    delay(100);
    
}

}
