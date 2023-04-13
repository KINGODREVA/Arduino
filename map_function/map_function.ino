const int analogPin = A0;
const int ledPin = 10;


void setup()
{
  Serial.begin(9600);
}

void loop() 
{
  int sensorInput = analogRead(analogPin);
  int val = map(sensorInput, 0 ,1023, 0 ,255);
  if ( val == 150)
  {
    analogWrite(ledPin, val);
    Serial.println(val);
  }
  else
  {
    analogWrite(ledPin, 0);
  }
  
  //analogWrite(ledPin, sensorInput);
  
  //int analogValue = analogRead(analogPin);
  //Serial.println(analogValue);
}
