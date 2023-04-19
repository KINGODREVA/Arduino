/*

#include <TimerOne.h>

const int LED = 10;

void setup() {
  Timer1.initialize();
  Timer1. pwm(LED, 0);

  Timer1.setPeriod(1000);
  //Timer1.setPwmDuty(LED, 200);
  // put your setup code here, to run once:

}

void loop() {
  for (int t_high=0; t_high <= 10; t_high++)
  {
    Timer1.setPwmDuty(LED, t_high*100);
    delay(100);
  }
}

*/

unsigned int x;

int main(void){
  
  Serial.begin(9600);
  TCCR1A = 0b00000000;
  TCCR1B = 0b00000101;

  while(1){
    //Serial.println(TCNT1);
    _delay_ms(100);
    x = x+100;
    Serial.println(x);
    
  }
}