#include <SoftwareSerial.h>

// 소프트웨어적으로 시리얼통신을 하기 위해 만들어줌.
SoftwareSerial mySerial(2,3); //(RX pin, TX pin); RX-받음. TX-보냄.

int led1 = 4;
int led2 = 8;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(mySerial.available()) {
    //Serial.write(mySerial.read()); 
    // └ 여기서 미리 읽어버리면 뒤에서 mySerial.read()에는 쓰레기값이 들어있게 된다.
    int read_data = mySerial.read();
    Serial.println(read_data);

    digitalWrite(led1, read_data);
    digitalWrite(led2, read_data);
  }
}
