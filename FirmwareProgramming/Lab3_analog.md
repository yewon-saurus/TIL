# 목차

[과제 1](#과제-1)

[과제 2](#과제-2)

[과제 3](#analogLab-HW)

# 과제 1

```arduino
int analogPin = 5;
int ledPin =  11;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogPin);  // 10 bit 0 ~ 1023
  analogWrite(ledPin, val>>2);     //  8 bit 0 ~ 255
  
  Serial.println(val);
  delay(1000);
}
```

```text
손가락이 터치되면 LED가 켜지고 다시 한 번 터치하면 꺼지는 소스 입니다. 스위치식 스탠드도 이 소스와 터치 센서를 이용하면 터치식으로 바꿀 수도 있겠네요.
```

# 과제 2

```arduino
#include <TM1637Display.h>

#define DIO 11
#define CLK 12
#define DIO 13
#define analogPin 5
#define FULL_ANGLE 280
#define MAX_ADC 1023.0

TM1637Display tm1637(CLK, DIO);
int adValue;
int degree;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  degree = 0;
  tm1637.setBrightness(0x04);
  tm1637.showNumberDec(degree);

}

void loop() {
  // put your main code here, to run repeatedly:
  adValue = analogRead(analogPin);  // 12 bit 0 ~ 1023
  Serial.println(adValue);

  degree = (int)((float)adValue * FULL_ANGLE / MAX_ADC);
  tm1637.showNumberDec(degree);
  delay(1000);
}
```

# analogLab HW

```arduino
#include <TM1637Display.h>

#define CLK 12
#define DIO 13
#define analogPin 5
#define FULL_ANGLE 280
#define MAX_ADC 1023.0

TM1637Display tm1637(CLK, DIO);
int adValue;
int degree;

const byte touch = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  degree = 0;
  tm1637.setBrightness(1);
  tm1637.showNumberDec(degree);

  pinMode(touch, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(touch), touched, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  adValue = analogRead(analogPin);  // 12 bit 0 ~ 1023
  
  tm1637.showNumberDec(degree);
}

void touched()
{
  degree = (int)((float)adValue * FULL_ANGLE / MAX_ADC);
}
```