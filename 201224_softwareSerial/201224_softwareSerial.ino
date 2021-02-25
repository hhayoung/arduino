#include <SoftwareSerial.h>

// 소프트웨어적으로 시리얼통신을 하기 위해 만들어 주겠다. 기존 핀을
SoftwareSerial mySerial(2,3); //(RX pin, TX pin); RX-받음. TX-보냄.
// 각각의 아두이노에서 2-3, 3-2와 연결해주면 된다.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  // 컴퓨터랑 연결하나, 아두이노랑 연결하나 그래서 2개의 통신이 필요하기 때문에 선언 필요
  // 다른 아두이노와 통신을 할 때는 mySerial을 이용하고,
  // 값을 보내줄 때는 Serial을 사용하면 된다.
}

void loop() {
  // put your main code here, to run repeatedly:
  if(mySerial.available()) {
    Serial.write(mySerial.read());
  }
}
