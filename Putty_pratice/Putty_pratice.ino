/*
int button1 = 7;
int button2 = 6;
const int sensor = 5;

int buttonState1 = 0;
int buttonState2 = 0;

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  // 버튼 1을 눌렸을 때 "테스트 시작"
  if (digitalRead(button1) == HIGH) {
    Serial.println("테스트 시작");
    delay(1000);
  }

  // 버튼 2를 눌렀을 때 "테스트 종료"
  else if (digitalRead(button2) == HIGH) {
    Serial.println("테스트 종료");
    delay(1000);
    }
  }
  */

int button1 = 7;
int button2 = 6;
const int sensor = 5;

int buttonState1 = 0;
int buttonState2 = 0;
int count = 0;

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {
  // 버튼 1을 눌렸을 때 "테스트 시작"
  if (digitalRead(button1) == HIGH) {
    Serial.println("테스트 시작");
    count++;
    while (count >= 1){
      int sensor = digitalRead(sensor);
      Serial.println(sensor);
      delay(1000);
    if(digitalRead(button2) == HIGH){
      count = 0;
      Serial.println("테스트 종료");
      delay(1000);
      break;
    }
    }
  }
}
