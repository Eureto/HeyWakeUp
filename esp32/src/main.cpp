
#include <Arduino.h>
#include <ESPAsyncWebServer.h>
#include <string>
#include <time.h>
const char *ntpServer = "0.pl.pool.ntp.org";
const long gmtOffset_sec = 3600;
const int daylightOffset_sec = 3600;
#define uS_TO_Minutes_FACTOR 60000000 /* Conversion factor for micro seconds to minutes */

int LocalTime()
{
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo))
  {
    Serial.println("Failed to obtain time");
    return 0;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
  int time = timeinfo.tm_hour * 100 + timeinfo.tm_min;
  Serial.println("time: " + String(time));
  return time;
}

#include <WiFi.h>
const char *ssid = "";
const char *password = "";
// Static IP configuration
IPAddress staticIP(192, 168, 0, 100); // ESP32 static IP
IPAddress gateway(192, 168, 0, 1);    // IP Address of your network gateway (router)
IPAddress subnet(255, 255, 255, 0);   // Subnet mask
IPAddress primaryDNS(192, 168, 0, 1); // Primary DNS (optional)
IPAddress secondaryDNS(0, 0, 0, 0);   // Secondary DNS (optional)

AsyncWebServer server(80);
int led_state = LOW;

#define LIGHT_SENSOR_PIN 34
#define LED_PIN 5
  int difTimeMinutes = 0;

void setLedState(int hour, int minutes, int timeAhead)
{
  int localTime = LocalTime();
  int localMinutes = localTime % 100;
  int localHour = localTime / 100;
  Serial.println("lokalna godizina " + String(localHour));
  Serial.println("lokalna minuta " + String(localMinutes));
  Serial.println("___________");
  Serial.println("ustawiona godzina " + String(hour));
  Serial.println("ustawiona minuta " + String(minutes));

  if (hour >= localHour)
  {
    difTimeMinutes = (hour - localHour) * 60 + minutes - localMinutes;
  }
  else
  {
    difTimeMinutes = (24 - localHour) * 60 + hour * 60 + minutes - localMinutes;
  }
  Serial.println("diftimeminutes: " + String(difTimeMinutes));
  esp_sleep_enable_timer_wakeup(difTimeMinutes * uS_TO_Minutes_FACTOR);
  Serial.println("Setup ESP32 to sleep for every " + String(difTimeMinutes) +
                 " minutes");
  esp_light_sleep_start();
  Serial.println("sie wybudzilem");
}

String getHTML()
{
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

void setup()
{
  Serial.begin(115200);
  pinMode(5, OUTPUT);

  Serial.print("czas dif: "+String(difTimeMinutes));
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  // Configuring static IP
  if (!WiFi.config(staticIP, gateway, subnet, primaryDNS, secondaryDNS))
  {
    Serial.println("Failed to configure Static IP");
  }
  else
  {
    Serial.println("Static IP configured!");
  }
  Serial.print("ESP32 Web Server's IP address: ");
  Serial.println(WiFi.localIP());

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  int asf = LocalTime();

  // Handling parameters in URL https://techtutorialsx.com/2017/12/17/esp32-arduino-http-server-getting-query-parameters/
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            {
 
    int hour, minute;
    int paramsNr = request->params();
    Serial.println(paramsNr);
 
    for(int i=0;i<paramsNr;i++){
 
        AsyncWebParameter* p = request->getParam(i);
        Serial.print("Param name: ");
        Serial.println(p->name());
        if(p->name() == "hour"){
          hour = p->value().toInt();
        }else if(p->name() == "minutes"){
          minute = p->value().toInt();
        }
        Serial.print("Param value: ");
        Serial.println(p->value());
        Serial.println("------");
    }
    request->send(200, "text/plain", "ok");
    setLedState(hour, minute, 0); });
  // Start the server
  server.begin();
}
int brightness{0};
void loop()
{
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
}
