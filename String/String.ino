String str1 = "kevincoolman" ;
String neme = "Napat Chobram";
int age = 1;
float gpa = 4.00;



void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.println("NAME : " + neme);
  Serial.println("AGE : " + String(age));
  Serial.println("gpa : " + String(gpa));
  delay(1000);
  

}
