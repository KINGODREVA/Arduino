// 버튼을 누르는 동안 LED와 buzzer가 작동

#include <TimerOne.h>

const int btn = 2;
const int LED = 10 ;
const int buzzer = 11;

int buttonState = 0;
bool ledOn = false;

void setup() {
  Serial.begin(9600);

  pinMode(btn, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Timer1.initialize(100000); // 0.1초 주기로 타이머 인터럽트 호출
  Timer1.attachInterrupt(timerCallback); // 타이머 인터럽트 콜백 함수 등록
}

void loop() {
  buttonState = digitalRead(btn);
  if (buttonState == HIGH && !ledOn) { // 버튼을 누르고 LED가 꺼져있는 경우
    Serial.println("Start");
    ledOn = true;
  } else if (buttonState == LOW && ledOn) { // 버튼을 떼고 LED가 켜져있는 경우
    Serial.println("bye");
    ledOn = false;
  }
}

void timerCallback() {
  if (ledOn) {
    analogWrite(LED, 255); // LED를 켜기 위해 duty cycle을 100%로 설정
    tone(buzzer, 262); // 262Hz 주파수의 소리 출력
  } else {
    analogWrite(LED, 0); // LED를 끄기 위해 duty cycle을 0%로 설정
    noTone(buzzer); // 부저 소리 중지
  }
}



