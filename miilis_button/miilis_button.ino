const int t1_LED = 13;

const int t2_LED = 10;


int button =2;

unsigned long cnt1 = 0;
unsigned long cnt2 = 0;
unsigned long times = 0;

int ledStates = 0;

void setup()
{
  pinMode(t1_LED, OUTPUT);
  pinMode(t2_LED, OUTPUT);
  pinMode(button, INPUT);
}

void loop()
{
  if(digitalRead(button) == HIGH && cnt1 == 0)
  {
    cnt1 = millis();
  }
  else if( cnt1 > 0 && digitalRead(button) ==LOW)
  {
    times = millis()-cnt1;
    cnt1 = 0;
  }
  else if(digitalRead(button)== LOW)
  {
    times = 0;
  }

  if(times > 0)
  {
    if( times > 2000)
    {
      ledStates = 1;
    }
    else if (times > 1000)
    {
      ledStates = 2;
    }

    cnt2 = millis();
    times = 0;
  }

  if(cnt2 > 0)
  {
    if(millis() > cnt2 + 2000)
    {
      cnt2 = 0;
      ledStates = 0;

      digitalWrite(t1_LED, LOW);
      digitalWrite(t2_LED, LOW);
    }

    switch(ledStates)
    {
      case 1:
      digitalWrite(t1_LED, HIGH);
      break;
      case 2:
      digitalWrite(t2_LED, HIGH);
      break;
      }
    }
  }
