#include <Wire.h>                                          //Napat Chobram No.12
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHTesp.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

#define DHTPIN 5

DHTesp dht;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
  Serial.begin(9600);
  Serial.println();
  Serial.println("Humidity (%)\tTemperature (C)\t(F)");
  
  dht.setup(DHTPIN, DHTesp::DHT22); // Change to DHTesp::DHT22 for DHT22 sensor

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Humidity Sensor");
  display.display();
  delay(2000);
  display.clearDisplay();
}

void loop() {
  float humidity = dht.getHumidity();
  float temperature = dht.getTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print("\t\t");
  Serial.println((temperature * 9 / 5) + 32, 1);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Humidity: ");
  display.print(humidity, 1);
  display.print("%");
  display.setCursor(0, 16);
  display.print("Temperature: ");
  display.print(temperature, 1);
  display.println("C");
  display.print("Temperature: ");
  display.print((temperature * 9 / 5) + 32, 1);
  display.println("F");
  display.display();

  delay(2000);
}
