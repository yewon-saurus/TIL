🔗 [아두이노 터치센서를 사용해서 LED 켜고 끄기](https://deneb21.tistory.com/384)

# 목차

[과제 1](#과제-1)

[과제 2](#과제-2)

[과제 3](#과제-3)

# 과제 1

```arduino
int touchSensor = 11; // 터치센서 핀 설정
int ledPin = 5; // LED 핀 설정

int state = LOW; // LED 상태
int reading; // 터치센서 상태
int previous = LOW; // 터치센서 이전 상태

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(touchSensor, INPUT); // 터치센서 설정
  pinMode(ledPin, OUTPUT); // ledPin 설정
}

void loop() {
  // put your main code here, to run repeatedly:
  reading = digitalRead(touchSensor); // touchSensor 상태 읽음

  if (reading == HIGH && previous == LOW) {
    if (state == HIGH) {
      state = LOW;
    } else {
      state = HIGH;
    }
  }
  
  digitalWrite(ledPin, state);

  previous = reading;
}
```

```text
손가락이 터치되면 LED가 켜지고 다시 한 번 터치하면 꺼지는 소스 입니다. 스위치식 스탠드도 이 소스와 터치 센서를 이용하면 터치식으로 바꿀 수도 있겠네요.
```

# 과제 2

```arduino
int touchSensor = 11;
int ledPin = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(touchSensor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int touchValue = digitalRead(touchSensor);

  if (touchValue == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("TOUCHED");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("NOT TOUCHED");
  }
}
```

# 과제 3

🔗 [KS0349 Keyestudio 48 in 1 Sensor Kit](https://www.dropbox.com/sh/s1p1r0xi7oud5t3/AADwGZNQln87CTtklquQswUTa?dl=0)

```arduino
int inputSensor = 11;
int buzzer = 5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  pinMode(inputSensor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int touchValue = digitalRead(inputSensor);

  if (touchValue == HIGH) {
    digitalWrite(buzzer, LOW);
    Serial.println("..");
  } else {
    digitalWrite(buzzer, HIGH);
    Serial.println("beep");
  }
}
```