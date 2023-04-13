
void setup()
{
  Serial.begin(9600);
  //pinMode(1, OUTPUT);
  //pinMode(2, OUTPUT);
  //pinMode(3, OUTPUT);
  //pinMode(4, OUTPUT);
  //pinMode(5, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(5, INPUT);
}

void loop()
{
  int button = digitalRead(5);
  Serial.println(button);

  if(button == HIGH){
    for(int i=8; i< 11; i++){
    digitalWrite(i,HIGH);
    delay(9);
    }

  }else{
     for(int i=8; i< 11; i++){
    digitalWrite(i,LOW);
    delay(1);
  }
  }
  }


  