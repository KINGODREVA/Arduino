#include <Servo.h>

Servo myservo;  // create servo object to control a servo

const int LED = 10;
const int analogPin = A0;

unsigned long t1_prev = 0;
unsigned long t2_prev = 0;

const unsigned long t1_delay = 4;
const unsigned long t2_delay = 10;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(analogPin, INPUT);
  myservo.attach(5);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
}

void loop() {

  unsigned long t1_now = millis();

  if(t1_now - t1_prev >= t1_delay)
  {
    t1_prev = t1_now;
    int t1_val = analogRead(analogPin);
    analogWrite(LED, t1_val/4);
  }

  unsigned long t2_now = millis();
  if(t2_now - t2_prev >= t2_delay)
  {
    t2_prev = t2_now;

    int t2_val = analogRead(analogPin);
    t2_val = map(t2_val, 0, 1023, 0, 180);
    myservo.write(t2_val);
  }
}
