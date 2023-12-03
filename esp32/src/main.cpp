
#include <Arduino.h>
#define LIGHT_SENSOR_PIN 34 // ESP32 pin GIOP34 (ADC0)
void setup() {
  Serial.begin(115200);
  pinMode(26, OUTPUT);
}
 int brightness{0};
void loop() {
  // reads the input on analog pin (value between 0 and 4095)
  int analogValue = analogRead(LIGHT_SENSOR_PIN);

  Serial.print("Analog Value = ");
  Serial.print(analogValue);   // the raw analog reading

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
 

//     analogWrite(26, brightness);
// brightness++;
// if ( brightness >= 255) {
//     brightness = 0;}



 digitalWrite(26, HIGH);

  delay(500);

 digitalWrite(26, LOW);

  delay(500);



}
