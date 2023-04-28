const int TRIG = 7;
const int ECHO = 6;

const int led_1 = 10;
const int led_2 = 9;
const int led_3 = 8;

void setup() {
  Serial.begin(9600);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);

}

void loop() {
  float duration, distance; // 초음파가 갔다가 돌아오는 시간과 거리 변수

  // 초음파 발사
  digitalWrite(TRIG, HIGH);
  //delay(10);
  digitalWrite(TRIG, LOW);
  
  // 초음파가 갔다가 돌아온 시간 저장
  duration = pulseIn(ECHO, HIGH);

  // 시간 -> 거리(cm)로 환산
  // distance = ((float)(duration * 340) / 10000) / 2;
  distance = duration * 0.034 / 2;

  // 시리얼 모니터에 거리 출력
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance <= 30)
  { 
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);
  }
  else
  {
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
  } 
}




