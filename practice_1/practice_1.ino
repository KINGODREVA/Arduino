// Blink 함수를 만들고 가변저항의 값이 100 이상일때만 작동하도록 하기. + 버튼을 누르면 탈출

const int led = 6;
// const int count = 10;
const int sensor = A0;
const int button = 7;

int buttonState = 0;


void blink()
{
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(led, LOW);
  delay(500);
}

void setup() {
  Serial.begin(9600);
  pinMode(led , OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(button, INPUT);
}

void loop() {
  
  while(analogRead(sensor) > 100)
  {
    blink();
    Serial.println(".");
  }
  if(digitalRead(7) == HIGH)
  {

  }
}
