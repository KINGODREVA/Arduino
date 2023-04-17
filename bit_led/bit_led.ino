// 비트 연산자 (AND, OR, XOR, NOT, SHIFT)

/*
int a = 12; // 1100 
int b = 14; // 1110
int c; // result

void setup() {
  Serial.begin(9600);
  
  Serial.print("AND : ");
  c = a & b; // 1100 & 1110 = 1100
  Serial.println(c);
  

  Serial.print("OR : ");
  c = a | b;
  Serial.println(c);


  Serial.print("XOR : ");
  c = a ^ b;
  Serial.println(c);


  Serial.print("NOT : ");
  c = ~a;
  Serial.println(c);

  Serial.print("Shift : ");
  c = 12 << 14;
  Serial.println(c);
 
  
}

void loop() {
  
}
*/

// (bit연산) 버튼으로 LED 제어하기

const int btn_pin = 2;
const int led_pin = 5;

void setup() {
  DDRD = B00100000;
  PORTD = B00000100;
}

void loop() {
  int btn = digitalRead(btn_pin);
  //int btn = (PIND & _BV(btn_pin)) >> btn_pin;

  if( btn == LOW) {
    PORTD = B00100000;
    //PORTD = _BV(led_pin) | PORTD;

  } else{
    PORTD = B00000100;
    //PORTD = -_BV(led_pin) & PORTD;
  }
}


