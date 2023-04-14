// 모터 핀
const int motor_A1 = 5;
const int motor_A2 = 6;
const int motor_B1 = 9;
const int motor_B2 = 10;


// 초음파 핀
const int TRIG = 3;
const int ECHO = 11;

// millis 변수 설정
unsigned long Timer_move = millis();

// 초음파 센서 거리 변수
float duration, distance;

// 라인트레이서 센서 핀
const int IR_R = A1;
const int IR_M = A3;
const int IR_L = A5;

// 라인트레이서 센서 데이터
int IR_L_data;
int IR_M_data;
int IR_R_data;

// 카운트
int cnt;


void setup() {
  // 모터
  pinMode(motor_A1, OUTPUT);
  pinMode(motor_A2, OUTPUT);
  pinMode(motor_B1, OUTPUT);
  pinMode(motor_B2, OUTPUT);

  // 라인 트레이서
  pinMode(IR_L, INPUT);
  pinMode(IR_M, INPUT);
  pinMode(IR_R, INPUT);

  // 초음파 센서
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  //Serial.begin(9600);
  //Serial.print("Start");
  //delay(1000);
}


void loop() {
  //IR 센서 값을 읽어 출력
  IR_L_data = digitalRead(IR_L);
  IR_M_data = digitalRead(IR_M);
  IR_R_data = digitalRead(IR_R);
  Serial.print(IR_L_data);
  Serial.print("-");
  Serial.print(IR_M_data);
  Serial.print("-");
  Serial.println(IR_R_data);
  
  // 초음파 센서 값
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // 거리
  duration = pulseIn(ECHO, HIGH);
  distance = (duration*.0343)/2;
  delay(100);

  
  // 아래 라인 트레이서 코드 (0이 흰색, 1이 검은색)
  if (Timer_move + 6000 > millis()){
  if (IR_L_data == 1 and IR_M_data == 0 and IR_R_data == 1) {
    //Serial.println("직진");
    forward();
    //delay(100);
    //stop();
    cnt = 0;
  }
  else if (IR_L_data == 1 and IR_M_data == 1 and IR_R_data == 0) {
    //Serial.println("우회전");
    right();
    //delay(100);
    //stop();
    cnt = 0;
  }
  else if (IR_L_data == 1 and IR_M_data == 0 and IR_R_data == 0) {
    //Serial.println("우회전");
    right();
    //delay(100);
    //stop();
    cnt = 0;
  }
  else if (IR_L_data == 0 and IR_M_data == 1 and IR_R_data == 1) {
    //Serial.println("좌회전");
    left();
    //delay(100);
    //stop();
    cnt = 0;
  }
  else if (IR_L_data == 0 and IR_M_data == 0 and IR_R_data == 1) {
    //Serial.println("좌회전");
    left();
    //delay(100);
    //stop();
    cnt = 0;
  }
  else if (IR_L_data == 1 and IR_M_data == 1 and IR_R_data == 1) {
    //Serial.println("후진");
    backward();
    //delay(100);
    //stop();
    cnt = 0;
  }
  else if (IR_L_data == 0 and IR_M_data == 0 and IR_R_data == 0) {
    //Serial.println("후진");
    backward();
    cnt = 0;
  }
  else if (IR_L_data == 0 and IR_M_data == 1 and IR_R_data == 0) {
    //Serial.println("정지");
    cnt = 0;
    //delay(100);
    if(cnt>50){
      backward();
      stop();
    }
  else if (Timer_move + 6000 < millis()){
    stop();
    delay(50);
    cnt++;
    }
    Timer_move = 0;
  }
}

   // 초음파 거리별 장애물 회피 
  if(distance <= 10){
    stop();
    delay(500);
    backward();
    }
  else if(distance > 10 && distance <= 20){
    left();
  }
  else if(distance > 20 && distance <= 30){
    right();
  }
}

void right () {
  //우
  digitalWrite(motor_A1, HIGH);
  digitalWrite(motor_A2, LOW);
  digitalWrite(motor_B1, LOW);
  digitalWrite(motor_B2, 150);
}

void left() {
  //좌
  digitalWrite(motor_A1, LOW);
  digitalWrite(motor_A2, 150);
  digitalWrite(motor_B1, HIGH);
  digitalWrite(motor_B2, LOW);
}

void forward() {
  //전진
  digitalWrite(motor_A1, HIGH);
  digitalWrite(motor_A2, LOW);
  digitalWrite(motor_B1, HIGH);
  digitalWrite(motor_B2, LOW);
}

void backward() {
  //후진
  digitalWrite(motor_A1, LOW);
  digitalWrite(motor_A2, HIGH);
  digitalWrite(motor_B1, LOW);
  digitalWrite(motor_B2, HIGH);
}

void stop() {
  //정지
  digitalWrite(motor_A1, LOW);
  digitalWrite(motor_A2, LOW);
  digitalWrite(motor_B1, LOW);
  digitalWrite(motor_B2, LOW);
}

/*
void leftback() {
  //좌로 후진
  digitalWrite(motor_A1, LOW);
  digitalWrite(motor_A2, 150);
  digitalWrite(motor_B1, HIGH);
  digitalWrite(motor_B2, LOW);
}

void rightback() {
  //우로 후진
  digitalWrite(motor_A1, HIGH);
  digitalWrite(motor_A2, LOW);
  digitalWrite(motor_B1, LOW);
  digitalWrite(motor_B2, 150);
}
*/
