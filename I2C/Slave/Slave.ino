// SPI

/*
#include <SPI.h>
byte count;

void setup (void)
{
  // SPI 통신을 위한 핀들의 입출력 설정
  pinMode(MISO, OUTPUT);
  pinMode(MOSI, INPUT);
  pinMode(SCK, INPUT);
  pinMode(SS, INPUT);
  // 마스터의 전송 속도에 맞추어 통신 속도를 설정한다.
  SPI.setClockDivider(SPI_CLOCK_DIV16);
  // SPI 통신을 위한 레지스터를 설정
  SPCR |= _BV(SPE); // SPI 활성화
  SPCR &= ~_BV(MSTR); // Slave 모드 선택
  SPCR |= _BV(SPIE); // 인터럽트 허용
  count = '0'; // 카운터 초기화
}
// SPI 통신으로 데이터가 수신될 때 발생하는 인터럽트 처리 루틴
ISR (SPI_STC_vect)
{
  SPDR = count;  // 카운터 값을 ASCII 값으로 전달
}
void loop (void)
{
  count = (count + 1) ; // 카운터 값 증가

  delay(1000);
}
*/

// I2C

/*
#include <Wire.h>
#define SLAVE 4
byte count = 'A'; // 카운터
void setup() {
  // Wire 라이브러리 초기화
  // 슬레이브로 참여하기 위해서는 주소를 지정해야 한다.
  Wire.begin(SLAVE);
  // 마스터의 데이터 전송 요구가 있을 때 처리할 함수 등록
  Wire.onRequest(sendToMaster);
}

void loop () {
}

void sendToMaster() {
  Wire.write(++count); // 카운터 값을 증가시키고 마스터로 전송
  
  if(count >= 'z'){
    count = 'A';
  }
}
*/

/*
#include <Wire.h>
#define SLAVE 4
#define ECHO_PIN 10
#define TRIG_PIN 11

byte duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  Wire.begin(SLAVE);
  // 마스터의 데이터 전송 요구가 있을 때 처리할 함수 등록
  Wire.onRequest(sendToMaster);
}

void loop () {

}

void sendToMaster() {
  digitalWrite(TRIG_PIN, LOW);

  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);

  delayMicroseconds(10);

  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn (ECHO_PIN, HIGH);

  distance = duration;

  delay(500);

  Serial.print(distance); //측정된 물체로부터 거리값(cm값)을 보여줍니다.

  Serial.println(" Cm");
}
*/

#include <Wire.h>

#define SLAVE_ADDRESS 4
#define ECHO_PIN 10
#define TRIG_PIN 11
#define ARRAY_SIZE 5 

byte distances[ARRAY_SIZE];
int currentIndex = 0; 

void setup() {
  Serial.begin(9600);
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  Wire.begin(SLAVE_ADDRESS);
  Wire.onRequest(sendToMaster);
}

void loop() {

  distances[currentIndex] = getDistance();
  
  currentIndex = (currentIndex + 1) % ARRAY_SIZE;
  
  delay(500);
}

void sendToMaster() {
  Wire.write(distances, ARRAY_SIZE);
}

byte getDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  byte duration = pulseIn(ECHO_PIN, HIGH);
  byte distance = duration;
  
  Serial.print(distance);
  Serial.println(" cm");
  
  return distance;
}

