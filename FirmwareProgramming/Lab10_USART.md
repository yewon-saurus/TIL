# 목차

[과제 1](#과제-1)

# 과제 1

```arduino
String inputString = "";	// 직렬통신 입력 문자열
String outputString = "";	// 출력 문자열
bool stringComplete = false;	// 계산식 입력이 완료되었음을 표시하는 플래그

void setup() {
  Serial.begin(9600);
  Serial.println("Digital Caculator");
}

void loop() {
  int len, a, b, ans;	// 입력 문자열 길이, 첫번째 변수, 두번째 변수, 덧셈값
  int ch;	  	// 입력한 문자 하나
  int sw;		// a를 입력 중인지 b를 입력 중인지 구별하는 플래그
  int n;		// 반복문 제어 변수

  if (stringComplete) {
    len = inputString.length();
    inputString.remove(len-1);
    Serial.print("Input: ");
    Serial.println(inputString);
    a = b = sw = ans = 0; // 첫 번째 변수, 두 번째 변수, 덧셈값을 0으로 초기화
    for (n=0; n<len; n++) { // 입력 문자열을 처음부터 끝까지 읽으면서..
      ch = inputString.charAt(n);
      if (ch == '+') { // 덧셈 표시가 나오면
        sw = 1; // a의 입력이 완료 되었음을 알리는 플래그 설정
      }
      else if (ch>='0' && ch<='9') {
        if (sw == 0) // 아직 a가 입력이 안됐어요
          a = a*10 + ch - '0';  // 뒤에 애들도 a 에요 -> 여러자리 수 를 입력받기 위해 이런 처리
        else // 숫자의 아스키 코드로 맞춰주기 위해..
          b = b*10 + ch - '0';
      }
      else if (ch == '=') {
        ans = a + b;
      }
    } // end for
    outputString = "Result: " + String(a) + '+' + String(b) + '=' + String(ans) + '\n';
    Serial.println(outputString);
    
    inputString = "";
    sw = 0;
    stringComplete = false;
  }
}

void serialEvent()
{
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
```

```arduino
#include <TM1637Display.h>

#define LED 10
#define CLK 12
#define DIO 13

TM1637Display tm1637(CLK, DIO);

String inputString = "";
String inputDec = "0";
bool stringComplete = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  tm1637.setBrightness(0x04);
  tm1637.showNumberDec(inputDec.toInt());
}
void loop() {
  int len;
  String sub = inputString.substring(0, 3);

  if (stringComplete) {
    len = inputString.length();
    inputString.remove(len - 1);
    Serial.print("Input: ");
    Serial.println(inputString);

    // Serial.println(inputString);

    if(inputString.equalsIgnoreCase("LED ON")) {
      digitalWrite(LED, HIGH);
    }
    else if(inputString.equalsIgnoreCase("LED OFF")) {
      digitalWrite(LED, LOW);
    }
    else if(sub.equalsIgnoreCase("FND")) {
      inputDec = inputString.substring(4, 8);
      tm1637.showNumberDec(inputDec.toInt());
    }
    else {
      Serial.println("Command error");
    }

    inputString = "";
    stringComplete = false;
  }
}

void serialEvent()
{
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if (inChar == '\n') {
      stringComplete = true;
    }
  }
}
```
