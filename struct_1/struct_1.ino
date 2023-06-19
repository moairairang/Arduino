  struct LED{
  String name;
  int iot = 12;
  int ntp = 15;
  int wifi = 2;
  int bt = 17;
};

struct LED led1;
void setup() {
  Serial.begin(9600);
  pinMode(led1.iot,OUTPUT);
  pinMode(led1.ntp,OUTPUT);
  pinMode(led1.wifi,OUTPUT);
  pinMode(led1.bt,OUTPUT);
  digitalWrite(led1.iot,HIGH);
  digitalWrite(led1.ntp,HIGH);
  digitalWrite(led1.wifi,HIGH);
  digitalWrite(led1.bt,HIGH);
  led1.name = "DesignByChobram";
  
}

void loop() {
  Serial.println("HELLO "+led1.name);
  digitalWrite(led1.iot,LOW);
  delay(1000);
  digitalWrite(led1.iot,HIGH);
  delay(1000);
  digitalWrite(led1.ntp,LOW);
  delay(1000);
  digitalWrite(led1.ntp,HIGH);
  delay(1000);
  digitalWrite(led1.wifi,LOW);
  delay(1000);
  digitalWrite(led1.wifi,HIGH);
  delay(1000);
  digitalWrite(led1.bt,LOW);
  delay(1000);
  digitalWrite(led1.bt,HIGH);
  delay(1000);

}
