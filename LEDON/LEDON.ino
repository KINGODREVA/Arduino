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