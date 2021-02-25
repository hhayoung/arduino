int led[] = { 8,9,10,11,12 };
int light_cnt = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for(int i=0;i<5;i++) {
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // 데이터는 비트단위로 들어옴
  if(Serial.available()) { //내가 읽을 수 있는 데이터(뭔가 들어온 데이터)가 있냐 있으면 참, 없으면 거짓
//    Serial.write(Serial.read()); // avaliable()하기 때문에 read()할 수 있음.
    //한 비트씩 출력
    //노트북의 tx -> 아두이노의 rx가 Read()
    //노트북의 rx <- 아두이노의 tx가 Write()

    char read_data = Serial.read();
//    int read_data = Serial.read(); // 1: 49(아스키코드)
    Serial.println(read_data);
    // 10 -> stop bit. 통신이 끝났다고 뜨는 거의 아스키코드 숫자

    if(read_data == 'a' || read_data == 49) {
      lightoff(); lighton(1);
    } else if(read_data == 'b' || read_data == 50) {
      lightoff(); lighton(2);
    } else if(read_data == 'c' || read_data == 51) {
      lightoff(); lighton(3);
    } else if(read_data == 'd' || read_data == 52) {
      lightoff(); lighton(4);
    } else if(read_data == 'e' || read_data == 53) {
      lightoff(); lighton(5);
    } else if((read_data < 49 || read_data > 54) && read_data != 10) {
      lightoff();
    }

//    switch(read_data) {
//      case 'a': 
//      case 49: light_cnt = 1; lightoff(); lighton(1); break;
//      case 'b': 
//      case 50: light_cnt = 2; lightoff(); lighton(2); break;
//      case 'c': 
//      case 51: light_cnt = 3; lightoff(); lighton(3); break;
//      case 'd': 
//      case 52: light_cnt = 4; lightoff(); lighton(4); break;
//      case 'e': 
//      case 53: light_cnt = 5; lightoff(); lighton(5); break;
//      case 10: 
//      case 13: lightstay();
////      case 'x': lightoff(); light_cnt = 0; break;
//      default: light_cnt = 0; lightoff(); break;
//    }
  }
}
void lighton(int value) {
  for(int i=0;i<value;i++) {
    digitalWrite(led[i], HIGH);
  }
}
void lightoff() {
  for(int i=0;i<5;i++) {
    digitalWrite(led[i], LOW);
  }
}
