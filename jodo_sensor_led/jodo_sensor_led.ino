const int sensorMin = 0;    
const int sensorMax = 300; 
const int led = 5;
const int led2 = 6;


void setup() {
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // read the sensor:
  int sensorReading = analogRead(A1);
  int led = map(sensorReading, 0 ,1023, 0, 255);
  Serial.println(sensorReading);
  // map the sensor range to a range of four options:
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);

  // do something different depending on the range value:
  switch (range) {
    case 3:  // your hand is on the sensor
      Serial.println("dark");
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      break;
    case 2:  // your hand is close to the sensor
      Serial.println("dim");
      digitalWrite(5, HIGH);
      digitalWrite(6, LOW);
      break;
    case 1:  // your hand is a few inches from the sensor
      Serial.println("medium");
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      break;
    case 0:  // your hand is nowhere near the sensor
      Serial.println("bright");
      digitalWrite(5, HIGH);
      digitalWrite(6, HIGH);
      break;
  }
  delay(100);  // delay in between reads for stability
}
