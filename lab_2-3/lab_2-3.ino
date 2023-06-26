void setup() {
  Serial.begin(9600);
  pinMode(A1, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A2, OUTPUT);
 
}

void loop() {
  if (Serial.available() > 0) {
    char val = Serial.read();

    if (val == 'a') {
      analogWrite(A1, 255);
      analogWrite(A2, 0);
      analogWrite(A3, 0);
      delay(1000);
      analogWrite(A1, 0);
      analogWrite(A2, 0);
      analogWrite(A3, 0);
    } else if (val == 's') {
      analogWrite(A1, 0);
      analogWrite(A2, 255);
      analogWrite(A3, 0);
      delay(1000);
      analogWrite(A1, 0);
      analogWrite(A2, 0);
      analogWrite(A3, 0);
    } else if (val == 'd') {
      analogWrite(A1, 0);
      analogWrite(A2, 0);
      analogWrite(A3, 255);
      delay(1000);
      analogWrite(A1, 0);
      analogWrite(A2, 0);
      analogWrite(A3, 0);
    } else if (val == 'f') {
      analogWrite(A1, 255);
      analogWrite(A2, 255);
      analogWrite(A3, 255);
      delay(1000);
      analogWrite(A1, 0);
      analogWrite(A2, 0);
      analogWrite(A3, 0);
    }
  }
}
