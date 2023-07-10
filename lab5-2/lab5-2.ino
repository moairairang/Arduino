int pin1 = 12;
int pin2 = 14;
int pin3 = 27;

void setup()
{
Serial.begin(9600);
pinMode(pin1, OUTPUT);
pinMode(pin2, OUTPUT);
pinMode(pin3, OUTPUT);
attachInterrupt(1, blink, RISING);
// เลข 1 คือ Interrupt หมายเลข 1 จะอยู่ที่ ขา32
// blink คือ ชื่อฟังชันที่จะให้ไปทำ
// RISING คือ ถ้าขา3 มีการเปลี่ยนสถานะจาก LOW เป็น HIGH ให้ทำในฟังก์ชั่น blink
} 
void loop()
{
digitalWrite(pin1, HIGH);
delay(500);
digitalWrite(pin1, LOW);
delay(500);
digitalWrite(pin2, HIGH);
delay(500);
digitalWrite(pin2, LOW);
delay(500);
digitalWrite(pin3, HIGH);
delay(500);
digitalWrite(pin3, LOW);
delay(500);
Serial.println("LED OFF");
//digitalWrite(pin1, HIGH);
//digitalWrite(pin2, HIGH);
//digitalWrite(pin3, HIGH);
//delay(5000);
}



void blink()
{
Serial.println("Interrupt");
Serial.println("LED ON");
digitalWrite(pin1, LOW);
digitalWrite(pin2, LOW);
digitalWrite(pin3, LOW);
//digitalWrite(pin1, HIGH);
//delay(500);
//digitalWrite(pin1, LOW);
//delay(500);
//digitalWrite(pin2, HIGH);
//delay(500);
//digitalWrite(pin2, LOW);
//delay(500);
//digitalWrite(pin3, HIGH);
//delay(500);
//digitalWrite(pin3, LOW);
//delay(500);
}
