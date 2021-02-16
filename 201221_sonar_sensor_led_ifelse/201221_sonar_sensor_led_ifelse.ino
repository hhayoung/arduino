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
  }else if(distance > 10 and distance <=20) {
    digitalWrite(LED_pin, HIGH);
    delay(50);
    digitalWrite(LED_pin, LOW);
    delay(50); // 0.1초
    Serial.println("10cm < distance <= 20cm");
  }else if(distance > 20 and distance <= 30) {
    digitalWrite(LED_pin, HIGH);
    delay(500);
    digitalWrite(LED_pin, LOW);
    delay(500); // 켰다꺼졌다 한번씩 하는게 1초기 때문에 .5초씩으로 해줘야함
    Serial.println("20cm < distance <= 30cm");
  }else{
    digitalWrite(LED_pin, LOW);
    Serial.println("distance > 30cm");
  }
}
