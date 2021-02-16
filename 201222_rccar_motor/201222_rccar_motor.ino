// 모터만 돌리기 위한 간단한 코드

// 왼쪽 motor
int motor1A_pin = 9;
int motor2A_pin = 6;
// 오른쪽 motor
int motor1B_pin = 5;
int motor2B_pin = 3;

void setup() {
  // put your setup code here, to run once:
  // 모터 핀 설정
  pinMode(motor1A_pin,OUTPUT);
  pinMode(motor2A_pin,OUTPUT);
  pinMode(motor1B_pin,OUTPUT);
  pinMode(motor2B_pin,OUTPUT);
  // 시리얼 통신 설정
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(motor1A_pin, 255);
  analogWrite(motor2A_pin, 0);
//  analogWrite(motor1B_pin, 255);
//  analogWrite(motor2B_pin, 0);
  // -> 시계인지 반시계인지 모르니까 일단 테스트
  analogWrite(motor1B_pin, 0);
  analogWrite(motor2B_pin, 255);
  // -> 이제 같은 방향으로 바퀴가 돈다.
  // 뒤로 가게 하려면 0과 255 바꿔주기
  // 속도를 줄게 하려면 255보다 값을 낮춰주면 된다. 너무 낮게 하면 힘이 없어서 바퀴가 돌지 않음
  // 좌회전 하려면 왼쪽 바퀴 힘을 줄이고, 오른쪽 바퀴 힘을 세게 해주면 된다.
  // 우회전은 마찬가지로 오른쪽 바퀴 힘을 줄이고, 왼쪽 바퀴 힘 세게 해주면 됨.
  // 또는 바퀴 방향을 반대로 하면 제자리에서 회전
  delay(1000);
  
  analogWrite(motor1A_pin, 255);
  analogWrite(motor2A_pin, 0);
  analogWrite(motor1B_pin, 0);
  analogWrite(motor2B_pin, 180);
  
  delay(2000);
}
