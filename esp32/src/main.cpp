
#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>

const char *ssid = "";
const char *password = "";

AsyncWebServer server(80);
int led_state = LOW;

#define LIGHT_SENSOR_PIN 34 
#define LED_PIN 5 


String getHTML() {
  String html = "<!DOCTYPE HTML>";
  html += "<html>";
  html += "<head>";
  html += "<link rel='icon' href='data:,'>";
  html += "</head>";
  html += "<p>LED state: <span style='color: red;'>";

  if (led_state == LOW)
    html += "OFF";
  else
    html += "ON";

  html += "</span></p>";
  html += "<a href='/led1/on'>Turn ON</a>";
  html += "<br><br>";
  html += "<a href='/led1/off'>Turn OFF</a>";
  html += "</html>";

  return html;
}

void setup() {
  Serial.begin(115200);
  pinMode(5, OUTPUT);

WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("ESP32 Web Server's IP address: ");
  Serial.println(WiFi.localIP());

server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("ESP32 Web Server: New request received:");
    Serial.println("GET /");
    request->send(200, "text/html", getHTML());
  });

 server.on("/led1/on", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("ESP32 Web Server: New request received:");
    Serial.println("GET /led1/on");
    led_state = HIGH;
    digitalWrite(LED_PIN, led_state);
    request->send(200, "text/html", getHTML());
  });
  server.on("/led1/off", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("ESP32 Web Server: New request received:");
    Serial.println("GET /led1/off");
    led_state = LOW;
    digitalWrite(LED_PIN, led_state);
    request->send(200, "text/html", getHTML());
  });
   server.on("/led1/off", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("ESP32 Web Server: New request received:");
    Serial.println("GET /led1/off");
    led_state = LOW;
    digitalWrite(LED_PIN, led_state);
    request->send(200, "text/html", getHTML());
  });


  // Start the server
  server.begin();

}
 int brightness{0};
void loop() {
  // reads the input on analog pin (value between 0 and 4095)
  // int analogValue = analogRead(LIGHT_SENSOR_PIN);

  // Serial.print("Analog Value = ");
  // Serial.print(analogValue);   // the raw analog reading

  // We'll have a few threshholds, qualitatively determined
  // if (analogValue < 40) {
  //   Serial.println(" => Dark");
  //   analogWrite(26, 255);
  //   // digitalWrite(26, HIGH);
  // } else if (analogValue < 800) {
  //   Serial.println(" => Dim");
  //   analogWrite(26, 200);
  //   // digitalWrite(26, HIGH);
  // } else if (analogValue < 2000) {
  //   Serial.println(" => Light");
  //   analogWrite(26, 100);
  //   // digitalWrite(26, LOW);
  // } else if (analogValue < 3200) {
  //   Serial.println(" => Bright");
  //   // digitalWrite(26, LOW);
  //   analogWrite(26, 50);

  // } else {
  //   Serial.println(" => Very bright");
  //   // digitalWrite(26, LOW);
  //   analogWrite(26, 0);
  // }
 

//     analogWrite(5, brightness);
// brightness++;
// if ( brightness >= 255) {
//     brightness = 0;}
//      Serial.println(brightness);



//  digitalWrite(5, HIGH);
//      Serial.println("HIGH");

//   delay(1300);

//  digitalWrite(5, LOW);
//      Serial.println("LOW");

  // delay(3);



}
