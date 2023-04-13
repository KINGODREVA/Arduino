int speakerPin = 11;
const int switchPin = 8;

char notes[] = "gabygabyxzCDxzCDabywabywzCDEzCDEbywFCDEqywFGDEqi        azbC";

int length = sizeof(notes); // the number of notes

int beats[] = { 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 2,3,3,16,};

int tempo = 75;

void playTone(int tone, int duration) {

  for (long i = 0; i < duration * 1000L; i += tone * 2) {

    digitalWrite(speakerPin, HIGH);

    delayMicroseconds(tone);

    digitalWrite(speakerPin, LOW);

    delayMicroseconds(tone);

  }
}

void playNote(char note, int duration) {

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'x', 'a', 'z', 'b', 'C', 'y', 'D', 'w', 'E', 'F', 'q', 'G', 'i' };

  // c=C4, C = C5. These values have been tuned.

  int tones[] = { 1898, 1690, 1500, 1420, 1265, 1194, 1126, 1063, 1001, 947, 893, 843, 795, 749, 710, 668, 630, 594 };
  
  for (int i = 0; i < 18; i++) {
    if (names[i] == note) {
       playTone(tones[i], duration);
       }
       }
       }



void setup() {
  pinMode(switchPin, INPUT);
  digitalWrite(switchPin, LOW);
  pinMode(6, 1);
  pinMode(9, 1);
  pinMode(10, 1);

}

void loop() {
  int val = analogRead(A0);
  val = map(val, 0, 1023, 0, 255);

  analogWrite(6, val);
  analogWrite(9, val);
  analogWrite(10, val);
  pinMode(speakerPin, OUTPUT);
  if(digitalRead(switchPin) == 1)
  {
    for(int i = 0; i < length; i++)
    {
      if(notes[i] == ' ')
      {
        delay(beats[i]*tempo);
      }
      else{
        playNote(notes[i], beats[i]*tempo);
      }

      delay(tempo/2);
    }
    }
    delay(100);
}



