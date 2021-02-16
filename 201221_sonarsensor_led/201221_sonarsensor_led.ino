int Echo_pin = 6;
int Trig_pin = 2;
int LED_pin = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Echo_pin, INPUT);
  pinMode(Trig_pin, OUTPUT);
  pinMode(LED_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration, distance;

  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);

  duration = pulseIn(Echo_pin, HIGH);

  distance = duration * 17 / 1000;

  if(distance <= 10) {
    digitalWrite(LED_pin, HIGH);
    Serial.println("distance <= 10 cm");
  }else if(distance > 10 and distance <= 20) { // and, && 둘 다 가능.
    digitalWrite(LED_pin, HIGH);
    //delay(100); // 0.1초
    delay(50);
    digitalWrite(LED_pin, LOW);
    //delay(100);
    delay(50); // 합쳐서 0.1초가 되게끔
    Serial.println("10cm < distance <= 20cm");
  }else if(distance > 20 and distance <= 30) {
    digitalWrite(LED_pin, HIGH);
    //delay(1000); // 1초
    delay(500); 
    digitalWrite(LED_pin, LOW);
    //delay(1000);
    delay(500); // 한번 켰다 꺼지는데 1초가 걸리는거니까 0.5초로 설정
    Serial.println("20cm < distance <= 30cm");
  }else{
    digitalWrite(LED_pin, LOW);
    Serial.println("distance > 30cm");
  }

  // 센서에게 delay는 치명적이다. Hz(1초에 몇번 센싱하는지) Hz가 높을수록 좋은 것.
  // 딜레이를 줄 때마다 Hz가 줄어드는 것. 
  // 딜레이를 줘서 센서를 끄는게 아니라, 주기를 달리 해서 효율적으로 만들어줘야 한다.
  // 또는 interupt(인터럽트) 중간에 끼어들기
  // 지금 하는 일을 멈추는게 아니라 잠깐 하고 오는 것.
}
