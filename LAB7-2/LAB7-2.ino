#include <WiFi.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHTesp.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

#define DHTPIN 5

DHTesp dht;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const char* ssid = "PpPp";
const char* password = "123456789";

WiFiServer server(80);

String header;
String output26State = "off";
String output27State = "off";

const int output26 = 26;
const int output27 = 27;

unsigned long currentTime = millis();
unsigned long previousTime = 0;
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);
  pinMode(output26, OUTPUT);
  pinMode(output27, OUTPUT);
  digitalWrite(output26, LOW);
  digitalWrite(output27, LOW);

  dht.setup(DHTPIN, DHTesp::DHT22);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Humidity Sensor");
  display.display();
  delay(2000);
  display.clearDisplay();

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if (client) {
    currentTime = millis();
    previousTime = currentTime;
    Serial.println("New Client.");
    String currentLine = "";
    while (client.connected() && currentTime - previousTime <= timeoutTime) {
      currentTime = millis();
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        header += c;
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            if (header.indexOf("GET /26/on") >= 0) {
              Serial.println("GPIO 26 on");
              output26State = "on";
              digitalWrite(output26, HIGH);
            } else if (header.indexOf("GET /26/off") >= 0) {
              Serial.println("GPIO 26 off");
              output26State = "off";
              digitalWrite(output26, LOW);
            } else if (header.indexOf("GET /27/on") >= 0) {
              Serial.println("GPIO 27 on");
              output27State = "on";
              digitalWrite(output27, HIGH);
            } else if (header.indexOf("GET /27/off") >= 0) {
              Serial.println("GPIO 27 off");
              output27State = "off";
              digitalWrite(output27, LOW);
            }

            float humidity = dht.getHumidity();
            float temperature = dht.getTemperature();

            String htmlResponse = "<html><body>";
            htmlResponse += "<h1>ESP32 Web Server</h1>";
            htmlResponse += "<p>Humidity: " + String(humidity, 1) + "%</p>";
            htmlResponse += "<p>Temperature: " + String(temperature, 1) + "°C</p>";
            htmlResponse += "<p>IP Address: " + WiFi.localIP().toString() + "</p>";
            htmlResponse += "<p>GPIO 26 - State " + output26State + "</p>";
            if (output26State == "off") {
              htmlResponse += "<p><a href=\"/26/on\"><button class=\"button\">ON</button></a></p>";
            } else {
              htmlResponse += "<p><a href=\"/26/off\"><button class=\"button button2\">OFF</button></a></p>";
            }
            htmlResponse += "<p>GPIO 27 - State " + output27State + "</p>";
            if (output27State == "off") {
              htmlResponse += "<p><a href=\"/27/on\"><button class=\"button\">ON</button></a></p>";
            } else {
              htmlResponse += "<p><a href=\"/27/off\"><button class=\"button button2\">OFF</button></a></p>";
            }
            htmlResponse += "</body></html>";

            client.println(htmlResponse);
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    header = "";
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
