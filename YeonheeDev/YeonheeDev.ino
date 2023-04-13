// 입력에 따라 LED 켜고 끄기

/*const int LED = 13;


void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop()
{
  if(Serial.available())
  {
    char userInput = Serial.read();

    switch(userInput)
    {
      case '1':
      digitalWrite(LED, HIGH); break;
      case '2':
      digitalWrite(LED, LOW); break;
    }
  }
}
*/
// LED를 버튼을 이용해 하나씩 켜지게 하기

/*
const int ledPin[3] = {6,9,10};
const int btnPin = 7;

int buttonState = 0;

void setup()
{
  for(int i = 0; i<3; i++)
  {
    pinMode(i, OUTPUT);
  }
    pinMode(btnPin, INPUT);
}

void loop()
{
  buttonState = digitalRead(btnPin);
  if(buttonState == HIGH)
  {
    for(int i = 0; i<3; i++){
      digitalWrite(ledPin[i], HIGH);
      delay(200);
    }
  }
  else
  {
    for(int i=0; i<3; i++){
      digitalWrite(ledPin[i], LOW);
    }
  }
}
*/

#include <TimerOne.h>

int pins[] = {6, 9, 10};

void setup(){
  
  Serial.begin(9600);
  for(int i=0;i<3;i++){
    pinMode(pins[i],OUTPUT);
  } 
}

void loop(){
  
  if(Serial.available())
  {
    char userInput = Serial.read();

    switch(userInput)
    {
      case '1':
      digitalWrite(6, HIGH); break;
      case '2':
      digitalWrite(6, LOW); break;
      case '3':
      digitalWrite(9, HIGH); break;
      case '4':
      digitalWrite(9, LOW); break;
      case '5':
      digitalWrite(10, HIGH); break;
      case '6':
      digitalWrite(10, LOW); break;
    }
  }
}

























