int Echo_pin = 6;
int Trig_pin = 2;
int swPin = 13;
int led[] = {8,9,10,11,12};
int pastData = 0;
int count = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(Echo_pin, INPUT);
  pinMode(Trig_pin, OUTPUT);
  pinMode(swPin, INPUT);
  for(int i=0;i<5;i++) {
    pinMode(led[i], OUTPUT);
  }
}

void loop()
{
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

  int newData = digitalRead(swPin); // 누르면 1, 떼면 0 값이 들어옴.
  Serial.print("sw_data : ");
  Serial.println(newData);

//  int flag = 0;
  //강사님코드
//  if(pastData!=newData) {
//    pastData = newData;
//    if(newData == LOW) {
//      // falling 하강 엣지
//      flag += 1;
//    }
//    else {
//      // rising 상승 엣지
//      // 둘 중 하나만 사용하면 됨.
//    }
//  }
//  if(flag == 1) {
//    for(int i=0;i<5;i++) {
//      digitalWrite(led[i], HIGH);
//    }
//  }else {
//    for(int i=0;i<5;i++) {
//      digitalWrite(led[i], LOW);
//    }
//    flag = 0;
//  }
  
  //내코드
  if (newData!=pastData) {
    pastData = newData;
    count++;
  }
  if(count%4==2) {
    for(int i=0;i<5;i++) {
      digitalWrite(led[i], HIGH);
    }
  } else {
    for(int i=0;i<5;i++) {
      digitalWrite(led[i], LOW);
    }
  }
}
