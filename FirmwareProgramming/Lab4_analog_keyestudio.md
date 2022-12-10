🔗 [KS0349 Keyestudio 48 in 1 Sensor Kit](https://www.dropbox.com/sh/s1p1r0xi7oud5t3/AADwGZNQln87CTtklquQswUTa?dl=0)

# 목차

[아날로그 센서](#아날로그-센서)

[자외선 센서](#자외선-센서)

[조이스틱](#조이스틱)

[온도 센서](#온도-센서)

[과제 1](#과제-1)

# 아날로그 센서

```arduino
int temt6000Pin = 0; // 아날로그 핀 설정 - A0에 연걸
 
void setup() {
  Serial.begin(9600);
 
}
 
void loop() {
  int value = analogRead(temt6000Pin); // 현재의 센서 값을 읽어온다
  Serial.println(value);
  delay(100); //only here to slow down the output so it is easier toread
}
```

# 자외선 센서

```arduino
int c=0; // 아날로그 핀 설정 - A0에 센서 연결
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  int sensorValue = analogRead(A0);
  // Serial.println(c++);
  Serial.println(sensorValue);
  delay(100);
}
```

```
키 스튜디오 GUVA-S12SD 자외선 센서는 자외선을 감지하는 데 사용된다. 시계와 같은 지능형 웨어러블 기기의 자외선 지수를 측정하기 위해 적용된 GUVA-S12SD를 포함한다.
UV 지수 감지 기능이 있는 스마트폰 및 실외 장치. 자외선의 강도를 모니터링 하거나 자외선으로 사물을 소독할 때 UV 화염 감지기로도 사용할 수 있다.
```

# 조이스틱


```arduino
int JoyStick_X = 0; // x
int JoyStick_Y = 1; // y
int JoyStick_Z = 3; // key, digital
 
void setup()
{
  pinMode(JoyStick_Z, INPUT); // joystick 입력을 읽는다
  Serial.begin(9600); // 9600 bps
}
 
void loop()
{
  int x,y,z;
  x = analogRead(JoyStick_X); // joystick의 x축 좌표(0 ~ 1023) 읽음 (평상시 512 근처)
  y = analogRead(JoyStick_Y); // joystick의 y축 좌표 읽음
  z = digitalRead(JoyStick_Z); // joystick의 디지털 입력 읽음(평상시 0, 클릭시 1)
  x = (x >> 6) - 7; // 값 재설정, 평상시 값이 512 근처가 아닌 0으로 출력되도록
  y = (y >> 6) - 7;
  Serial.print(x ,DEC);
  Serial.print(",");
  Serial.print(y ,DEC);
  Serial.print(",");
  Serial.println(z ,DEC);
  delay(100);
}
```

```
Lots of robot projects need joystick. This module provides an affordable solution. By simply connecting to two analog inputs, the robot is at your commands with X, Y control. It also has as witch that is connected to a digital pin.
```

```
많은 로봇 프로젝트들이 조이스틱을 필요로 한다. 이 모듈은 경제적인 솔루션을 제공합니다. 두 개의 아날로그 입력에 연결하는 것만으로 X, Y 컨트롤로 로봇을 마음대로 조작할 수 있습니다. 그것은 또한 디지털 핀에 연결된 스위치를 가지고 있다.
```

# 온도 센서

```arduino
void setup()
{
  Serial.begin(9600);//Set Baud Rate to 9600 bps
}
 
void loop()
{
  int val;
  int dat;
  val=analogRead(0); // A0에 연결된 아날로그 센서의 값 읽기
  dat=(500 * val) /1024;; // 온도 계산(주변 공기 온도)
  Serial.print("Temp:"); // 이하 Serial.print -> Serial monitor에 현재 온도 출력
  Serial.print(dat);
  Serial.println("C");
  delay(500);
}
```

```
LM35 Linear Temperature Sensor is based on semiconductor LM35 temperature sensor. It can be used to detect ambient air temperature. This sensor offers a functional range among 0 degree Celsius to 100 degree Celsius. Sensitivity is 10mV per degree Celsius. The output voltage is proportional to the temperature. This sensor is commonly used as a temperature measurement sensor. It includes thermocouples, platinum resistance, thermal resistance and temperature semiconductor chips. The chip is commonly used in high temperature measurement thermocouples. Platinum resistance temperature sensor is used in the measurement of 800 degrees Celsius, while the thermal resistance and semiconductor temperature sensor is suitable for measuring the temperature of 100-200 degrees or below, in which the application of a simple semiconductor temperature sensor is good in linearity and high in sensitivity. The LM35 linear temperature sensor can be easily connected to Arduino shield.
```

```
LM35 리니어 온도 센서는 반도체 LM35 온도 센서를 기반으로 합니다. 주변 공기 온도를 감지하는 데 사용할 수 있습니다. 이 센서는 섭씨 0도에서 100도 사이의 기능 범위를 제공합니다. 감도는 섭씨 10mV이다. 출력 전압은 온도에 비례합니다. 이 센서는 일반적으로 온도 측정 센서로 사용됩니다. 열전대, 백금 저항, 내열성 및 온도 반도체 칩을 포함합니다. 이 칩은 일반적으로 고온 측정 열전대에 사용됩니다. 백금 저항 온도 센서는 섭씨 800도의 측정에 사용되는 반면, 열 저항 및 반도체 온도 센서는 100~200도 이하의 온도 측정에 적합하며, 간단한 반도체 온도 센서의 적용은 선형성이 우수하고 감도가 높다. LM35 선형 온도 센서는 아두이노 실드에 쉽게 연결할 수 있습니다.
```

# 과제 1

```arduino
#include <TM1637Display.h>

int JoyStick_X = 1; // x - A0
int JoyStick_Y = 0; // y - A1
int JoyStick_Z = 3; // key, digital - D3

#define CLK 12
#define DIO 13
TM1637Display display(CLK, DIO);

int redled = 11; // D11
int yellowled = 10; // D10
int greenled = 9; // D9

void setup()
{
  pinMode(JoyStick_Z, INPUT); // joystick 핀 설정
  Serial.begin(9600); // 9600 bps

  display.setBrightness(1); // 4-digit 표시장치 밝기 설정

  pinMode(redled, OUTPUT); // 신호등 핀 설정
  pinMode(yellowled, OUTPUT);
  pinMode(greenled, OUTPUT);
}
 
void loop()
{
  int x,y,z;
  x = analogRead(JoyStick_X); // joystick의 x축 좌표(0 ~ 1023) 읽음 (평상시 512 근처)
  y = analogRead(JoyStick_Y); // joystick의 y축 좌표 읽음
  z = digitalRead(JoyStick_Z); // joystick의 디지털 입력 읽음(평상시 0, 클릭시 1)
  x = (x >> 2) - 124;
  y = (int)(((y >> 2) - 122) * 100 / 122);

  if (x > 0)
  {
    analogWrite(greenled, x); // turn on green LED
  }
  else
  {
    analogWrite(greenled, LOW); // turn off LED
  }
  if (x < 0)
  {
    analogWrite(yellowled, -(x)); // turn on yellow LED
  }
  else
  {
    analogWrite(yellowled, LOW);
  }
  if (z == 1)
  {
    digitalWrite(redled, HIGH); // turn on red LED
  }
  else
  {
    digitalWrite(redled, LOW);
  }

  delay(100);

  if (y > 100)
  {
    display.showNumberDec(100);
  }
  else
  {
    display.showNumberDec(y);
  }
}
```