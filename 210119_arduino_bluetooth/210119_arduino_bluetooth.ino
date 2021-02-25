#include <SoftwareSerial.h>

int blueTx = 2; // 보내는 핀
int blueRx = 3; // 받는 핀
int led = 13;

SoftwareSerial mySerial(blueTx, blueRx);

String myString = ""; // 받는 문자열

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(mySerial.available()) {
    char myChar = (char)mySerial.read();
    myString += myChar;
    delay(5); // 수신 문자열 끊김 방지
  }
  if(!myString.equals("")) {
    Serial.println("input value : "+myString);

    if(myString == "on") {
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
    }
    
    myString = ""; // 초기화
  }
}
