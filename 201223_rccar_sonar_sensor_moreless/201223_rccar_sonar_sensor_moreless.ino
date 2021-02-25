// ROS책을 가지고 일정거리 30cm(오차±5cm)를 유지하게 하는 코드
// 책이 멀어지면 전진, 책이 가까워지면 후진

// 왼쪽 motor
int motor1A_pin = 9;
int motor2A_pin = 6;
// 오른쪽 motor
int motor1B_pin = 5;
int motor2B_pin = 3;

// 초음파센서
int echo_pin = 10;
int trig_pin = 11;

// 시간 조절
int ctr_time = 1000;

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
  // put your main code here, to run repeatedly:
  
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
  for(int i=150;i<200;i++) {
    analogWrite(motor1A_pin, i);
    analogWrite(motor2A_pin, 0);
    analogWrite(motor1B_pin, 0);
    analogWrite(motor2B_pin, i);
  }
  delay(ctr_time);
}
void motorBack() {
  // 후진
  for(int i=200;i>150;i--) {
    analogWrite(motor1A_pin, 0);
    analogWrite(motor2A_pin, i);
    analogWrite(motor1B_pin, i);
    analogWrite(motor2B_pin, 0);
  }
  delay(ctr_time); 
  // 딜레이는 기계한테는 최악이기 때문에 딜레이를 쓰지 않고, 
  // for문 횟수를 늘리고 시간은 동일하게 조정해서 프로그램이 쉬지 않도록 해줌. 
  // 이런 원리는 맞는데 중간중간 속도를 가져와서 또 if문 쓰고 그러면 너무 복잡해지니까
  // interrupt는 사용해야 하는데 아직 안배웠으니 패쓰. 거기다가
  // 일단 가속 감속은 지금 모터가 꾸져서 현재는 별로 뭐 보이는게 없기 때문에 해봤자다.
}
void motorStop() {
  // 정지
  analogWrite(motor1A_pin, 0);
  analogWrite(motor2A_pin, 0);
  analogWrite(motor1B_pin, 0);
  analogWrite(motor2B_pin, 0);
}
