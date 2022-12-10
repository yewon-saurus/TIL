# 목차

[과제 1](#과제-1)

[과제 2](#과제-2)

# 과제 1

## 문제 1

```arduino
#include <TM1637Display.h>

#define DIO 11
#define CLK 10
#define analogPin 5
#define FULL_ANGLE 280
#define MAX_ADC 1023.0

TM1637Display tm1637(CLK, DIO);
int adValue;
int degree;

unsigned long start;
unsigned long end;

void setup() {
Serial.begin(9600);
  degree = 0;
  tm1637.setBrightness(0x04);
  tm1637.showNumberDec(degree);
}

void loop() {
  start = micros(); // 함수 호출 전, 시간 측정
  adValue = analogRead(analogPin);  // 12 bit 0 ~ 1023
  end = micros();  // 함수 호출 후, 시간 측정
  Serial.print(end - start); // 시간의 차를 시리얼 모니터에 출력
  Serial.print(", ");

  degree = (int)((float)adValue * FULL_ANGLE / MAX_ADC);
  start = micros();
  tm1637.showNumberDec(degree);
  end = micros();
  Serial.println(end - start);

  delay(1000);
}
```

## 문제 2

```arduino
#include <TimerOne.h>

#define LED 11
#define analogPin 5

int value = 0;
bool ledState = LOW;
long int tPeriod;
int tFlag;

void setup()
{
  pinMode(LED, OUTPUT);
  tPeriod = 1000000;
  Timer1.initialize(tPeriod);
  Timer1.attachInterrupt(blinked); // ISR
}

void loop()
{
  if (tFlag == 1)
  {
    analogWrite(LED, value);
    tFlag = 0;
  }
}

void blinked()
{
  value = analogRead(analogPin); // 0 ~ 1023 
  value = map(value, 0, 1023, 255, 0);
  Timer1.setPeriod(tPeriod/value); // msec 주기가 analogPin에서 읽어 온 value 값에 반비례 하도록
  tFlag = 1;
}
```

# 과제 2

## 문제 1

```arduino
#include <TM1637Display.h>
#include <TimerOne.h>

#define CLK 12
#define DIO 13
#define TOUCH 3

TM1637Display tm1637(CLK,DIO);
bool isTouched = false;
long int tPeriod = 0; 
long int timer = 0;
int tick = 0;
int Dots = 0;

void setup()
{
  pinMode(TOUCH, INPUT);

  tm1637.setBrightness(0x01);
  tm1637.showNumberDec(0);
  tPeriod = 50000; // 50,000us = 50ms = 0.05s

  Timer1.initialize(tPeriod); // Timer1 간격을 tPeriod로 설정

  attachInterrupt(digitalPinToInterrupt(TOUCH), touched, RISING);
  Timer1.attachInterrupt(ISR005, tPeriod); // Timer1 인터럽트 발생 시, ISR055 호출
}
void loop()
{
    tm1637.showNumberDecEx(timer, Dots, 1); // leading zero = true
}

void touched()
{
  isTouched = !isTouched;
  if(isTouched){
    timer = 0;
  }
}
void ISR005()
{
  if(isTouched){ // 터치가 됐는가? isTouched가 True라면
    tick += 1; // tick 1번 카운트 사 -> 0.05초
    if(tick == 10){ // 0.5초
      Dots = 0; // 콜론(:) 감추기
    }
    if(tick == 20){  // 1초 
      Dots = 0x40; // 콜론(:) 나타나기
      timer += 1; // 시간이 1초 지났으므로
      tick = 0;
    }
  }
}
```

## 문제 2

```arduino
#define LED 11

void setup()
{
  Serial.begin(9600);
  pinMode(LED, INPUT);
}
void loop()
{
  digitalWrite(LED, HIGH);
  delay(300);

  digitalWrite(LED, LOW);
  delay(700);
}
```

```arduino
#include <TimerOne.h>

#define LED 10

void setup()
{
  pinMode(LED, OUTPUT);
  Timer1.initialize(1000000);
}
void loop()
{
  Timer1.pwm(LED, 306); // 0 ~ 1023
}
```

```arduino
#include <TimerOne.h>

#define LED 10

bool isLight=false;
long int tMicros=0;
long int tPeriod=100000; // 100,000us = 100ms = 0.1s

void setup()
{
  pinMode(LED, OUTPUT);

  Timer1.initialize(tPeriod);
  Timer1.attachInterrupt(ISR03, tPeriod);
}
void loop()
{
  digitalWrite(LED, isLight);
}
void ISR03()
{
  tMicros = tMicros + tPeriod;
  if(tMicros >= tPeriod * 10) { // 0.1s * 10 = 1s
    tMicros = 0;
  }
  if(tMicros < tPeriod * 3) {// 0.3초 켜기 0 1 2 
    isLight = true;
  }
  else { // 0.7초 끄기 3 4 5 6 7 8 9 
      isLight = false;
  }
}
```