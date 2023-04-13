#include <TimerOne.h>

const int BUZZER = 10;

void setup() {
  Timer1.initialize();
  Timer1.pwm(BUZZER, 0);

  Timer1.setPwmDuty(BUZZER, 512);

  Timer1.setPeriod(1000000/262);

  delay(3000);
  
  Timer1.setPwmDuty(BUZZER, 0);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
