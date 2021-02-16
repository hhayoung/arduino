int Echo_pin = 6;
int Trig_pin = 2;

void setup() {
  Serial.begin(9600);
  // 핀설정(input으로 할지 output으로 할지)
  //pinMode(6, INPUT); // Echo를 6번 pin에 꽂아놨음.
  //값들을 여러곳에서 쓰게 될 때 모두 바꾸는건 힘드니까 변수화
  pinMode(Echo_pin,INPUT);
  pinMode(Trig_pin,OUTPUT); // 신호를 보낼 거니까 OUTPUT
}

void loop() {
  //long time <- 주황색으로 바뀜. 이미 함수로 되어있는 이름이라서 변수로 쓸 수 없음
  long duration, distance;
  // -> cm를 mm로 바꾸려고 하면
  float duration, distance;
  
  //하나의 디지털신호 파형 만들기
  digitalWrite(Trig_pin, LOW); // 현재로서는 점만 찍은 상태
  //유지시켜주고 싶을 때는 delay사용, 초음파 센서는 마이크로세컨드니까 그게 맞춰서 사용. 원래 쓰던 delay()는 단위가 ms이기 때문에
  delayMicroseconds(2); // 아주 짧지만 잠깐동안의 시간을 딜레이 시켜줌
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  // -> 하나의 ∏ 신호파형이 만들어졌다.

  // 만든 파형이 들어오는 거니까 pulseIn. 정보를 받는다=활성화시킨다=HIGH
  duration = pulseIn(Echo_pin, HIGH);
  
  distance = duration * 17 / 1000;
  // -> cm로 출력하기 위해서 cm로 바꿔주기. 
// 공식 도출 못했다고 하면, 문서에 있었던 58로 나누면 된다.
// -> cm를 mm로 바꾸려면
distance = duration * 17 / 1000 * 10;

  Serial.print(“distance : “);
  Serial.print(distance);
  Serial.println(“cm “);
  delay(10);
}
