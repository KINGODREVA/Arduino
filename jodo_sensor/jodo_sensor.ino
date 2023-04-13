/*
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
      Serial.print(distance);
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
*/

// 적외선 센서
/*
int sensor = 3;              // 라인트레이서 센서을 9번 핀에 연결
int Buzzer = 11;              // Buzzer를 7번 핀에 연결
void setup() {
  Serial.begin(9600);
  pinMode(Buzzer, OUTPUT);   // Buzzer는 '출력'
  pinMode(sensor, INPUT);    // 라인트레이서 센서는 '입력'
}
void loop() {
  int val = digitalRead(sensor);  // 센서 값을 읽어와서
  Serial.println(val);
  if (val == HIGH) {         // 검정색 주행선 위에 있으면
    noTone(11);               // Buzzer에서 소리가 나지 않는다
    delay(100);
  } else {                   // 검정색 주행선을 벗어나면
    tone(11, 220);            // Buzzer에서 소리가 난다
    delay(100);
  }
}
*/

//조도 센서

void setup() {

  Serial.begin(9600); 
  pinMode(10, INPUT); 
}

void loop() 
{
  if (digitalRead(10) == HIGH) 
  {
    Serial.println("CDS off");  // 빛이차단되면 출력됩니다
  }
 delay(500);
}

