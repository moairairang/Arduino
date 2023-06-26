int i = 0;
void setup() {
  Serial.begin (9600);
}
void loop() {
  if (Serial.available () > 0) {
    char In = Serial.read(); //อ่านค่าจากพอร์ตมาเก็บไว้ในต้าแปร
    Serial.print("num i:") ;
    Serial.println(i); // พิมพ์ค่าของตำแปร 1 ออกทางจอมอนเตอร์
    Serial.print("Count data:") ;
    Serial. println(Serial.available ()) ;//พิมพ์จำนานข้อมูลที่ยังไม่อ่านออกทางจอมอนิเตอร์
    Serial.print("character:");
    Serial.println(In); // พิมพ์ค่าของตำแปร IN ออกทางจอมอนิเตอร์
    delay(1000) ; //หน่างเวลา 1 วินาที
    i++;
  }
}
