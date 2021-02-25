// ROS책을 가지고 일정거리 30cm(오차±5cm)를 유지하게 하는 코드
// 책이 멀어지면 전진, 책이 가까워지면 후진

// 왼쪽 motor
int motor1A_pin = 9;
int motor2A_pin = 6;
// 오른쪽 motor
int motor1B_pin = 5;
int motor2B_pin = 3;

// 초음파센서
int echo_pin = 12;
int trig_pin = 13;

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
}

void loop() {
  // put your main code here, to run repeatedly
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

  Serial.print("distance : ");
  Serial.print(distance);
  Serial.println("cm");

  compDist(distance);
  
}
void compDist(int distance) {
  if(distance > 35) {
    motorFront();
  } else if(distance < 25) {
    motorBack();
  } else if(distance >= 25 && distance <= 35) {
    motorStop();
  }else if(distance > 50) {
    motorStop();
  }
}
void motorFront() {
  // 전진
  analogWrite(motor1A_pin, 200);
  analogWrite(motor2A_pin, 0);
  analogWrite(motor1B_pin, 0);
  analogWrite(motor2B_pin, 200);
}
void motorBack() {
  // 후진
  analogWrite(motor1A_pin, 0);
  analogWrite(motor2A_pin, 200);
  analogWrite(motor1B_pin, 200);
  analogWrite(motor2B_pin, 0);
}
void motorStop() {
  // 정지
  analogWrite(motor1A_pin, 0);
  analogWrite(motor2A_pin, 0);
  analogWrite(motor1B_pin, 0);
  analogWrite(motor2B_pin, 0);

}
