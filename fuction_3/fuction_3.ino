int iot = 12;
int ntp = 15;
int wifi = 2;
int led4 = 17;

void setup() {
  pinMode(iot , OUTPUT);
  pinMode(ntp , OUTPUT);
  pinMode(wifi , OUTPUT);
  pinMode(led4 , OUTPUT);
  digitalWrite(iot , HIGH);
  digitalWrite(ntp , HIGH);
  digitalWrite(wifi , HIGH);
  digitalWrite(led4 , HIGH);

}

void loop() {
  bling(100);
  bling2();
  wifiblink(100);
 

}
