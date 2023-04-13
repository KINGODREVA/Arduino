// 버튼을 누를때 마다 서브모터 각도가 10도씩 증가하는 코드

#include <Servo.h>

Servo servo;
int servoPin = 5;
int buttonPin = 6;
int buttonState = 0;
int lastButtonState = 0;
int angle = 0;

void setup() {
  servo.attach(servoPin);
  pinMode(buttonPin, INPUT);
}

void loop() {

  int buttonInput = digitalRead(buttonPin);

  if(buttonState == LOW && lastButtonState == HIGH) 
  {
  angle += 10;
    if (angle >= 180) {
      angle = 0;
    }
    servo.write(angle);
  }
    
    buttonState == lastButtonState;
    delay(50);
}
  

