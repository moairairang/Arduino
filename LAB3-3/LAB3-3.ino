#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht;
void setup()
{
  Serial.begin(9600);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");
  dht.setup(2); 
  lcd.begin();
  lcd.backlight();

}
void loop() {
  delay(dht.getMinimumSamplingPeriod());

  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature(); 

  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print("\t\t");
  Serial.println(dht.toFahrenheit(temperature), 1);
  lcd.setCursor(0, 1);
  lcd.print("Hum:      ");
  lcd.setCursor(4, 1);
  lcd.print(humidity);
  lcd.setCursor(9, 1);
  lcd.print("%");
  lcd.setCursor(0, 0);
  lcd.print("Temp:      ");
  lcd.setCursor(5, 0);
  lcd.print(temperature);
  lcd.setCursor(9, 0);
  lcd.print("C ");
  lcd.print(dht.toFahrenheit(temperature), 1);
  lcd.print("F");
  delay(100);

}
