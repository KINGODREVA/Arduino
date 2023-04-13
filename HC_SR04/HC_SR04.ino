const int led = 6;
const int led2 = 5;
const int trigPin = 10;  
const int echoPin = 9;
const int button1 = 7;
const int button2 = 8;
const int buzzer =  11;

int buttonstate1 = 0;
int buttonstate2 = 0;

float duration, distance;  

void setup() {  
	pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(buzzer, OUTPUT);
	Serial.begin(9600);  
}  

void loop() 
{ 
   int count = 0;
  buttonstate2 = digitalRead(button2);
  if (buttonstate2 == HIGH) 
  {
    count = count + 1;
  }
   while (count == 1) {
     if(digitalRead(button1) == LOW)
     {
       digitalWrite(trigPin, LOW);
       delayMicroseconds(2);
       digitalWrite(trigPin, HIGH);
       delayMicroseconds(10);
       digitalWrite(trigPin, LOW);
      
      unsigned long duration = pulseIn(echoPin, HIGH);
      //long distance = (duration/2) / 29.1;
      float distance = (duration/2) / 29.1;
      //digitalWrite(echoPin, LOW);
      //digitalWrite(led, HIGH);
      Serial.print("Distance: ");  
      Serial.println(distance);
      delay(1000);

      if (distance < 30 && distance >= 20) {
        digitalWrite(led, HIGH);
        digitalWrite(led2, LOW);
        tone(buzzer, 523, 1000/8);
        delay(1000/ 2*1.30);
        noTone(buzzer);
      }
      else if (distance < 10 && distance >= 1) {
        digitalWrite(led, LOW);
        digitalWrite(led2, HIGH);
        tone(buzzer, 740, 1000/8);
        delay(1000 / 4*1.30);
        noTone(buzzer);
      } 
      else {
        digitalWrite(led, LOW);
        digitalWrite(led2, LOW);
      }
    } else {
      count = 0;
    }
  }
}
  /*if(distance > 10)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
  */
