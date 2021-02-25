// 서보모터 사용방법
// 서보모터는 아두이노에서 이미 만들어져있는 라이브러리를 추가해줘야 한다.
#include <Servo.h>

Servo SB1;
int servo_pin = 10; // pwm 번호여야 함.

void setup() {
  // put your setup code here, to run once:
  SB1.attach(servo_pin);
}

void loop() {
  // put your main code here, to run repeatedly:
  // 0~180 사이만 움직임. 아날로그기 때문에 pwm 핀으로 사용해줘야 함.
  // 기존 pwm핀번호를 다 쓰고 있어서 초음파센서를 옮겨주고 써야 한다. 
//  SB1.write(0); // 오른쪽
//  delay(1000);
//  SB1.write(180); // 왼쪽
//  delay(1000);
  SB1.write(90);  // 정면
  delay(1000);
}
