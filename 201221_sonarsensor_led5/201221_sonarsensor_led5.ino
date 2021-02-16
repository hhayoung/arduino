int Echo_pin = 6;
int Trig_pin = 2;
int LED_pin1 = 8;
int LED_pin2 = 9;
int LED_pin3 = 10;
int LED_pin4 = 11;
int LED_pin5 = 12;
int state1, state2, state3, state4, state5 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Echo_pin, INPUT);
  pinMode(Trig_pin, OUTPUT);
  pinMode(LED_pin1, OUTPUT);
  pinMode(LED_pin2, OUTPUT);
  pinMode(LED_pin3, OUTPUT);
  pinMode(LED_pin4, OUTPUT);
  pinMode(LED_pin5, OUTPUT);
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
    state1 = LOW;
    state2 = LOW;
    state3 = LOW;
    state4 = LOW;
    state5 = LOW;
    Serial.println("distance <= 10 cm");
  }else if(distance > 10 and distance <= 20) { // and, && 둘 다 가능.
    state1 = HIGH;
    state2 = LOW;
    state3 = LOW;
    state4 = LOW;
    state5 = LOW;
    Serial.println("10cm < distance <= 20cm");
  }else if(distance > 20 and distance <= 30) {
    state1 = HIGH;
    state2 = HIGH;
    state3 = LOW;
    state4 = LOW;
    state5 = LOW;
    Serial.println("20cm < distance <= 30cm");
  }else if(distance > 30 and distance <= 40) {
    state1 = HIGH;
    state2 = HIGH;
    state3 = HIGH;
    state4 = LOW;
    state5 = LOW;
    Serial.println("30cm < distance <= 40cm");
  }else if(distance > 40 and distance <= 50) {
    state1 = HIGH;
    state2 = HIGH;
    state3 = HIGH;
    state4 = HIGH;
    state5 = LOW;
    Serial.println("40cm < distance <= 50cm");
  }else{
    state1 = HIGH;
    state2 = HIGH;
    state3 = HIGH;
    state4 = HIGH;
    state5 = HIGH;
    Serial.println("distance > 50cm");
  }
  digitalWrite(LED_pin1, state1);
  digitalWrite(LED_pin2, state2);
  digitalWrite(LED_pin3, state3);
  digitalWrite(LED_pin4, state4);
  digitalWrite(LED_pin5, state5);
}
