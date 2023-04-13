// this constant won't change:
const int buttonPin1 = 7;  // the pin that the pushbutton is attached to
const int buttonPin2 = 8;
const int ledPin1 = 5;
const int ledPin2 = 6;    // the pin that the LED is attached to

// Variables will change:
int buttonPushCounter1 = 0;  // counter for the number of button presses
int buttonState1 = 0;        // current state of the button
int lastButtonState1 = 0;    // previous state of the button

// Variables will change:
int buttonPushCounter2 = 2;  // counter for the number of button presses
int buttonState2 = 2;        // current state of the button
int lastButtonState2 = 2;    // previous state of the button

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin1, INPUT);
  // initialize the button pin as a input:
  pinMode(buttonPin2, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin1, OUTPUT);
  // initialize serial communication:
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
}

void led_1()
{
  digitalWrite(ledPin1, HIGH);
  delay(100);
  // digitalWirte(ledPin1, LOW);
  // delay(100);
}

void led_2()
{
  digitalWrite(ledPin2, HIGH);
  delay(100);
  // digitalWrite(ledPin2, LOW);
  // delay(100);
}

void loop() {
  // read the pushbutton input pin:
  buttonState1 = digitalRead(buttonPin1);

  // compare the buttonState to its previous state
  if (buttonState1 != lastButtonState1) {
    // if the state has changed, increment the counter
    if (buttonState1 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter1++;
      Serial.println("on");
      // Serial.print("number of button pushes: ");
      // Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState1 = buttonState1;

  buttonState2 = digitalRead(buttonPin2);

  // compare the buttonState to its previous state
  if (buttonState2 != lastButtonState2) {
    // if the state has changed, increment the counter
    if (buttonState2 == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter2++;
      Serial.println("on");
      // Serial.print("number of button pushes: ");
      // Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState2 = buttonState2;


  // turns on the LED every four button pushes by checking the modulo of the
  // button push counter. the modulo function gives you the remainder of the
  // division of two numbers:
  if (buttonPushCounter1 % 2 == 0) {
    int val = analogRead(analogWrite);
    Serial.println(val);
    delay(100);
    // digitalWrite(ledPin1, HIGH);
    led_1();
    } else {
  digitalWrite(ledPin1, LOW);
  if (buttonPushCounter2 % 4 == 0) {
    int val = analogRead(analogWrite);
    Serial.println(val);
    delay(100);
    // digitalWrite(ledPin1, HIGH);
    led_2();
  } else {
    digitalWrite(ledPin2, LOW);
  }
}
}

