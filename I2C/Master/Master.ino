// UART

/*
char message = 'A';


void setup(){
  Serial.begin(9600);
  Serial.println("UART");
}

void loop(){
  Serial.println(message);
  message++;
  
  if(message > 'z'){
    message = 'A';
  }  
  delay(1000);
}



void setup(){
  Serial.begin(9600);
}

void loop(){
  while(Serial.available()){
    char data = Serial.read();
    Serial.print(data);
  }  
}
*/

/*
// SPI


#include <SPI.h>
void setup (void)
{
  SPI.begin (); // SPI 통신 초기화
  digitalWrite(SS, HIGH); // 슬레이브가 선택되지 않은 상태로 유지
  // 안정적인 전송을 위해 분주비를 높여 전송 속도를 낮춤
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  Serial.begin(9600);
}
void loop (void)
{
  if(Serial.available()){
    char data = Serial.read(); // 데이터 입력 확인
    if(data == 'K'){
      digitalWrite(SS, LOW); // 슬레이브를 선택한다.
      // 1바이트 데이터 수신을 위해 의미 없는 1바이트 데이터를 전송한다.
      char received = SPI.transfer(0);
      digitalWrite(SS, HIGH); // 슬레이브 선택을 해제한다.
      Serial.println(received);
    }
  }
}
*/

// I2C

/*
#include <Wire.h>
#define SLAVE 4 // 슬레이브 주소
void setup() {
  Wire.begin(); // Wire 라이브러리 초기화
  Serial.begin(9600); // 직렬 통신 초기화
  Serial.println("I2C");
}
void loop() {
  i2c_communication(); // 슬레이브로 데이터 요구 및 수신 데이터 처리
  delay(1000);
}
void i2c_communication() {
  Wire.requestFrom(SLAVE, 1); // 1 바이트 크기의 데이터 요청
  char c = Wire.read(); // 수신 데이터 읽기
  Serial.println(c); // 수신 데이터 출력
}
*/

#include <Wire.h>
#define SLAVE 4 // 슬레이브 주소
void setup() {
  Wire.begin(); // Wire 라이브러리 초기화
  Serial.begin(9600); // 직렬 통신 초기화
  Serial.println("START");
}
void loop() {
  i2c_communication(); // 슬레이브로 데이터 요구 및 수신 데이터 처리
  delay(1000);
}
void i2c_communication() {
  Wire.requestFrom(SLAVE, 1); // 1 바이트 크기의 데이터 요청
  //byte c = Wire.read(); // 수신 데이터 읽기
  Serial.println(Wire.read()); // 수신 데이터 출력
}



 



