# 목차

[과제 1](#과제-1)

[과제 2](#과제-2)

# 과제 1

```arduino
const byte touch = 2;
const byte ratch = 3;
const byte led = 11;

int touchValue = LOW;

void setup()
{
  // 터치 센서
  pinMode(touch, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(touch), ctrlLED, RISING);

  // 래치형 터치 센서
  pinMode(ratch, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ratch), ctrlLED, CHANGE);

  // LED 출력
  pinMode(led, OUTPUT);
}

void loop()
{
  digitalWrite(led, touchValue);
}

void ctrlLED()
{
  if (touchValue == HIGH) {
    touchValue = LOW;
  }
  else {
    touchValue = HIGH;
  }
}
```

# 과제 2

```arduino
#include <TM1637Display.h>

const byte touch = 2;
const byte ratch = 3;

#define CLK 12 // definitions for TM1637 and can be changed to other ports
#define DIO 13
TM1637Display display(CLK, DIO);

int num = 0;

void setup()
{
  // 4-자리 표시장치 밝기 설정
  display.setBrightness(1);

  // 터치 센서
  pinMode(touch, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(touch), up, RISING);

  // 래치형 터치 센서
  pinMode(ratch, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ratch), down, CHANGE);
}

void loop()
{
  display.showNumberDec(num);
}

void up()
{
  num++;
}

void down()
{
  if (num > 0) {
    num--;
  }
}
```
