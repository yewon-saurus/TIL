# 목차

[과제 1](#과제-1)

[과제 2](#과제-2)

# 과제 1

```arduino
#include <OneWire.h>
#include <TimerOne.h>

OneWire ds(11); // on pin 11 (a 4.7K resistor is necessary)
byte ds_addr[8];

uint8_t found;
uint8_t scratchpad[10];
int tick = 0;
int flag1 = 0;
int flag2 = 0;
int16_t raw; // raw data
float celcius; // temperature
char buf[80]; // print buffer

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // timerISR 0.1 초마다 실행되도록 설정
  Timer1.initialize(100000);
  Timer1.attachInterrupt(TimerISR);

  found = ds.search(ds_addr);
  if (found) {
    sprintf(buf, "ROM addr: %2x, %2x, %2x, %2x, %2x, %2x, %2x, %2x",
    ds_addr[0], ds_addr[1], ds_addr[2], ds_addr[3], ds_addr[4],
    ds_addr[5], ds_addr[6], ds_addr[7]);
    Serial.println(buf);
 }
}

void TimerISR()
{
  tick = (tick+10) % 200;  // 2초 주기

  if (tick == 0){
    flag1 = 1;    // 0초  -> start
  }
  if (tick == 100){   // 
    flag2 = 1;   // 1초   ->  read
  }
}

void loop() {

  if (found) {
    if(flag1 == 1){   // 0초 -> start
      ds.reset();
      ds.select(ds_addr);  
      ds.write(0x44, 1); // start conversion
      flag1 = 0;     // 다시 0으로 set
    }
  
    if (flag2 == 1){    // 1초  ->  read
      ds.reset();
      ds.select(ds_addr);
      ds.write(0xBE); // read scratchpad
      ds.read_bytes(scratchpad, 9);

      for (int n=0; n<9; n++) {
        Serial.print(scratchpad[n]);
        Serial.print(" ");
      }

      Serial.println();
      raw = ((int16_t)scratchpad[1] << 8) + (int16_t)scratchpad[0];
      celcius = (float)raw/16.0;
      sprintf(buf, "Temperature: raw = %d ", raw);
      Serial.print(buf);
      Serial.println(celcius);
      flag2 = 0;     // 다시 0으로 set
    }   
  }
}
```

# 과제 2

```arduino
#include <TimerOne.h>

int echoPin=3; // define ultrasonic signal receiver pin ECHO to D3
int trigPin=5; // define ultrasonic signal transmitter pin TRIG to D5

int flag = 0;
unsigned long start = 0;
unsigned long end = 0;
char buf[80];

const unsigned long TIMER_INTERVAL = 1000000; // 타이머 인터럽트 주기

unsigned int tick = 0; // TimerISR에서 시간 누적

void setup()
{
  Serial.begin(9600); // Serial 초기화
  pinMode(echoPin, INPUT); // echoPin 입력 설정
  pinMode(trigPin, OUTPUT); // trigPin 출력 설정
  Timer1.initialize(TIMER_INTERVAL); // timer 초기화, 주기 0.1 sec
  Timer1.attachInterrupt(timer_tick); // timer interrupt 설정

  attachInterrupt(digitalPinToInterrupt(echoPin), blink, CHANGE);
}

void blink(){
  byte echo_pulse; // 지역 변수
  echo_pulse = digitalRead(echoPin); 

  if (echo_pulse == 1) { // high이면,
    flag = 1;
    start = micros();
  } // low이면, pulse width가 더해지지 않는다.
  else {
    flag = 2;
    end = micros(); 
  }
}

void timer_tick() // timer interrupt 초음파 START
{
  tick += 1;  // 1초 주기
}

void loop()
{
  // trigger pulse
  if (tick == 1) {
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH); // Pulse for 10μs to trigger ultrasonic detection
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    tick = 0;
  }

  // unsigned long pulseIn(pin, value): 핀으로 입력되는 펄스의 시간을 측정하는 함수
  // 핀의 입력이 LOW -> HIGH -> LOW가 될 때까지 시간을 마이크로초 단위로 리턴
  // timeout까지 펄스가 만들어지지 않으면 0을 리턴
  unsigned long echowidth = end - start;

  if (flag == 2) {
    unsigned long distance = echowidth * 170 / 1000; // Transform pulse time to distance
    sprintf(buf, "echo_width=%ld,  distance=%ld mm", echowidth, distance);
    Serial.println(buf);
    flag = 0;
  }
}
```