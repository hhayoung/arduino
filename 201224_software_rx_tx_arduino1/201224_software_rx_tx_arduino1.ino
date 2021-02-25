#include <SoftwareSerial.h>
// 소프트웨어 통신 rx pin = 2, tx pin = 3
SoftwareSerial mySerial(2,3);

int sw_pin = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(sw_pin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = digitalRead(sw_pin);
  Serial.println(data);
  mySerial.write(data);
}
