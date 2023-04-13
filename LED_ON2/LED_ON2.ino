// LED 8개 점등하기
/*
void setup()
{
  //pinMode(1, OUTPUT);
  //pinMode(2, OUTPUT);
  //pinMode(3, OUTPUT);
  //pinMode(4, OUTPUT);
  //pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  //digitalWrite(1, HIGH);
  //delay(1000); // Wait for 1000 millisecond(s)
  //digitalWrite(1, LOW);
  //delay(1000); // Wait for 1000 millisecond(s)
  //digitalWrite(2, HIGH);
  //delay(1000); // Wait for 1000 millisecond(s)
  //digitalWrite(2, LOW);
  //delay(1000); // Wait for 1000 millisecond(s)
  //digitalWrite(3, HIGH);
  //delay(1000); // Wait for 1000 millisecond(s)
  //digitalWrite(3, LOW);
  //delay(1000); // Wait for 1000 millisecond(s)
  //digitalWrite(4, HIGH);
  //delay(1000); // Wait for 1000 millisecond(s)
  //digitalWrite(4, LOW);
  //delay(1000); // Wait for 1000 millisecond(s)
  //digitalWrite(5, HIGH);
  //delay(1000); // Wait for 1000 millisecond(s)
  //digitalWrite(5, LOW);
  //(1000); // Wait for 1000 millisecond(s)
  digitalWrite(6, HIGH);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(6, LOW);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(7, HIGH);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(7, LOW);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(8, HIGH);
  delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(8, LOW);
  delay(500); // Wait for 1000 millisecond(s)
}
*/

/* 
void setup()
{
  for(int i=0; i<9; i++){
    pinMode(i,OUTPUT);
  }
}

void loop()
{
  for(int i = 0; i <9; i++){
    digitalWrite(i, HIGH);
  }
  delay(1000);
  
  for(int i = 0; i <9; i--){
    digitalWrite(i, LOW);
  }
  delay(1000);
}
*/

/*
// 차례대로 점등하기
void setup()
 {
   pinMode(1, OUTPUT);
   pinMode(2, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(6, OUTPUT);
   pinMode(7, OUTPUT);
   pinMode(8, OUTPUT);
}

void loop() {
    digitalWrite(1,HIGH);
    delay(100);
    digitalWrite(1,LOW);
    delay(100);

    digitalWrite(2,HIGH);
    delay(200);
    digitalWrite(2,LOW);
    delay(200);

    digitalWrite(3,HIGH);
    delay(300);
    digitalWrite(3,LOW);
    delay(300);

    digitalWrite(4,HIGH);
    delay(400);
    digitalWrite(4,LOW);
    delay(400);

     digitalWrite(5,HIGH);
    delay(500);
    digitalWrite(5,LOW);
    delay(500);

     digitalWrite(6,HIGH);
    delay(600);
    digitalWrite(6,LOW);
    delay(600);

     digitalWrite(7,HIGH);
    delay(700);
    digitalWrite(7,LOW);
    delay(700);

     digitalWrite(8,HIGH);
    delay(800);
    digitalWrite(8,LOW);
    delay(800);
}
*/

/*
//교차 점등
void setup()
{
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(8, HIGH);
  delay(1000);
  
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  digitalWrite(8, LOW);
  delay(1000);
  
  digitalWrite(1, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(7, HIGH);
  delay(500);
  
  digitalWrite(1, LOW);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  digitalWrite(7, LOW);
  delay(500);
}
*/

// 스위치를 이용해 LED 제어

/*
void setup()
{
  Serial.begin(9600);
  //pinMode(1, OUTPUT);
  //pinMode(2, OUTPUT);
  //pinMode(3, OUTPUT);
  //pinMode(4, OUTPUT);
  //pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(5, INPUT);
}

void loop()
{
  int readValue = digitalRead(5);
  Serial.println(readValue);
  
  if(readValue == HIGH)
  {
    digitalWrite(8, HIGH);
  }
  else 
  {
    digitalWrite(8, LOW);
  }
  
  digitalWrite(6, HIGH);
  delay(500); // Wait for 1000 millisecond(s)
 // digitalWrite(6, LOW);
  //delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(7, HIGH);
  delay(500); // Wait for 1000 millisecond(s)
  //digitalWrite(7, LOW);
  //delay(500); // Wait for 1000 millisecond(s)
  digitalWrite(8, HIGH);
  delay(500); // Wait for 1000 millisecond(s)
  //digitalWrite(8, LOW);
  //delay(500); // Wait for 1000 millisecond(s)
}
*/
int ledState = HIGH;        // the current state of the output pin
int buttonState;            // the current reading from the input pin
int lastButtonState = LOW;  //


void setup()
{
  Serial.begin(9600);
  //pinMode(1, OUTPUT);
  //pinMode(2, OUTPUT);
  //pinMode(3, OUTPUT);
  //pinMode(4, OUTPUT);
  //pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(5, INPUT);
}

void loop()
{
  int readValue = digitalRead(5);
  Serial.println(readValue);
  
  if(readValue == HIGH)
  {
    digitalWrite(6, HIGH);
  }
  else
  {
    digitalWrite(6, LOW);
  }
  
  digitalWrite(6, HIGH);
  delay(0);
  
  digitalWrite(7, HIGH);
  delay(0);
 
  digitalWrite(8, HIGH);
  delay(0);
  
  }
  

