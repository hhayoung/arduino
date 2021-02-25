#include <Servo.h>

// 왼쪽 motor
int motor1A_pin = 6;
int motor2A_pin = 9; // 자리바꿔줬음.
// 오른쪽 motor
int motor1B_pin = 5;
int motor2B_pin = 3; // -> 11번으로 

// 초음파센서
int echo_pin = 12;
int trig_pin = 13;

// 서보모터
Servo SB1;
int servo_pin = 10;
// 좌,우 거리값
int left, right = 0;

// 스위치
int sw_pin = 2; // -> 7번으로 
int count = 0;
int pastData = 1;

void setup() {
  // put your setup code here, to run once:
  // 모터 핀 설정
  pinMode(motor1A_pin,OUTPUT);
  pinMode(motor2A_pin,OUTPUT);
  pinMode(motor1B_pin,OUTPUT);
  pinMode(motor2B_pin,OUTPUT);
  // 시리얼 통신 설정
  Serial.begin(9600);
  // 초음파 센서 핀 설정
  pinMode(echo_pin, INPUT);   // 초음파를 받아들이기 때문에 INPUT
  pinMode(trig_pin, OUTPUT);  // 초음파를 쏘기 때문에 OUTPUT
  // 서보모터
  SB1.attach(servo_pin);
  // 스위치
  pinMode(sw_pin, INPUT);
}

int getDist() {

  long duration, distance;
  
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);

  // pulseIn() :  초음파가 장애물에 부딪혀서 돌아온 왕복 시간
  //              LOW->HIGH로 바뀔 때 시간 측정 시작
  duration = pulseIn(echo_pin, HIGH);

  distance = duration * 17 / 1000; // cm

  return distance;
}

void loop() {
  // put your main code here, to run repeatedly:

  int newData = digitalRead(sw_pin); // 누르면 0, 떼면 1값이 들어옴.

  Serial.println(newData);
  
  if(pastData!=newData) {
    pastData = newData;
    if(newData == LOW) {
      // falling 하강 엣지
      count++;
    }
  }

  if(count%2==1 && newData==HIGH) {
    SB1.write(90);
    delay(100);
  
    long distance = getDist();
  
    Serial.print("distance : ");
    Serial.print(distance);
    Serial.println("cm");
  
    if(distance < 20) {
      motorStop();
      delay(500);
      servoMotor();
    } else {
      motorFront();
    }
  } else {
    motorStop();
  }
}

void compDist(int distance) {
  if(distance < 20) {
    motorStop();
    servoMotor();
  } else {
    motorFront();
  }
}

void servoMotor() {

//  int left, right = 0;

  // 왼쪽 거리값
  SB1.write(180);
  delay(500);
  left = getDist();
  Serial.print("left distance : ");
  Serial.println(left);
  delay(500);
  
//  SB1.write(90);
//  center = getDist();
//  Serial.print("center distance : ");
//  Serial.println(center);
//  delay(1000);

  // 오른쪽 거리값
  SB1.write(0);
  delay(500);
  right = getDist();
  Serial.print("right distance : ");
  Serial.println(right);
  delay(500);

  SB1.write(90);
  delay(1000);

  if(left > right) {
    motorLeft();
//    motorStop();
//    motorFront();
  } else if(left < right) {
    motorRight();
//    motorStop();
//    motorFront();
  } 
}
void motorFront() {
  // 전진
  Serial.println("직진중");
  analogWrite(motor1A_pin, 180);
  analogWrite(motor2A_pin, 0);
  analogWrite(motor1B_pin, 0);
  analogWrite(motor2B_pin, 170);
  
}
void motorRight() {
  // 우회전
  Serial.println("우회전중");
  analogWrite(motor1A_pin, 150);
  analogWrite(motor2A_pin, 0);
  analogWrite(motor1B_pin, 0);
  analogWrite(motor2B_pin, 0);
  delay(650);
//  SB1.write(90);
//  delay(500);
}
void motorLeft() {
  // 좌회전
  Serial.println("좌회전중");
  analogWrite(motor1A_pin, 0);
  analogWrite(motor2A_pin, 0);
  analogWrite(motor1B_pin, 0);
  analogWrite(motor2B_pin, 150);
  delay(650);
//  SB1.write(90);
//  delay(500);
}
void motorStop() {
  // 정지
  analogWrite(motor1A_pin, 0);
  analogWrite(motor2A_pin, 0);
  analogWrite(motor1B_pin, 0);
  analogWrite(motor2B_pin, 0);
//  delay(500);
}
