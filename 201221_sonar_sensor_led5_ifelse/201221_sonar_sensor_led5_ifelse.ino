int Echo_pin = 3;
int Trig_pin = 2;
int LED[5] = {8,9,10,11,12};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Echo_pin, INPUT);
  pinMode(Trig_pin, OUTPUT);
  for(int i=0;i<5;i++) {
    pinMode(LED[i], OUTPUT);
  }
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
    for(int i=0;i<5;i++) {
       digitalWrite(LED[i], LOW);
    }
    Serial.println("distance <= 10 cm");
  }else if(distance > 10 and distance <=20) {
    for(int i=0;i<1;i++) {
       digitalWrite(LED[i], HIGH);
    }
    for(int i=1;i<5;i++) {
       digitalWrite(LED[i], LOW);
    }
    Serial.println("10cm < distance <= 20cm");
  }else if(distance > 20 and distance <= 30) {
    for(int i=0;i<2;i++) {
       digitalWrite(LED[i], HIGH);
    }
    for(int i=2;i<5;i++) {
       digitalWrite(LED[i], LOW);
    }
    Serial.println("20cm < distance <= 30cm");
  }else if(distance > 30 and distance <= 40) {
    for(int i=0;i<3;i++) {
       digitalWrite(LED[i], HIGH);
    }
    for(int i=3;i<5;i++) {
       digitalWrite(LED[i], LOW);
    }
    Serial.println("30cm < distance <= 40cm");
  }else if(distance > 40 and distance <= 50) {
    for(int i=0;i<4;i++) {
       digitalWrite(LED[i], HIGH);
    }
    for(int i=4;i<5;i++) {
       digitalWrite(LED[i], LOW);
    }
    Serial.println("40cm < distance <= 50cm");
  }else{
    for(int i=0;i<5;i++) {
       digitalWrite(LED[i], HIGH);
    }
    Serial.println("distance > 50cm");
  }
}
