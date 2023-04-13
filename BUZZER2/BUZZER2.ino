int inputpin = 0;
int outputpin = 5;
int inputValue = 0;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  inputValue = analogRead(inputpin);
  if(0 <= inputValue && inputValue <= 100)
  {
    tone(outputpin, 523);
  }
  else if(101 <= inputValue && inputValue <= 200)
  {
    tone(outputpin, 587);
  }
  else if(201 <= inputValue && inputValue <= 300)
  {
    tone(outputpin, 659);
  }
  else if(301 <= inputValue && inputValue <= 400)
  {
    tone(outputpin,698);
  }
  else if(401 <= inputValue && inputValue <= 500)
  {
    tone(outputpin,784);
  }
  else if(501 <= inputValue && inputValue <= 600)
  {
    tone(outputpin, 880);
  }
  else if(601 <= inputValue && inputValue <= 700)
  {
    tone(outputpin, 987);
  }
  else if(701 <= inputValue && inputValue <= 800)
  {
    tone(outputpin, 1047);
  }
}
