# ios_base::sync_with_stdio(false); cin.tie(null); 구문을 추가해주는 이유

🔗 [ios_base::sync_with_stdio(false); cin.tie(null); 구문을 추가해주는 이유](https://jaimemin.tistory.com/1521)

```cpp
ios_base::sync_with_stdio(false);
cin.tie(null);
```

## ios_base::sync_with_stdio(false);의 장점

`ios_base::sync_with_stdio` -> 이 구문은

c의 stdio와 cpp의 iostream을 동기화시켜주는 역할을 하는데

이 때 iostream과 stdio의 버퍼를 모두!! 사용하기 때문에 딜레이가 발생을 하게 된답니다

따라서,

`ios_base::sync_with_stdio(false);`의 코드를 작성해줌으로써 동기화를 비활성화 시켜주는 것!!

이로 인해, C++만의 독립적인 버퍼가 생성되어

C의 버퍼와 병행하여 사용할 수 없게 되긴 하지만?

`사용하는 버퍼의 수가 줄어들었기 때문에` `실행 속도`는 빨라지는 것이지요~

알고리즘 문제를 풀 때는 대부분 `싱글 쓰레드 환경`이기 때문에, 해당 코드를 추가해줘도 문제가 발생하지 않을 확률이 높습니다.

## ios_base::sync_with_stdio(false);의 단점

동기화된 cpp의 버퍼의 경우,

thread-safe 하기 때문에

모든 IO의 순서가 예상한 것과 정확히! 일치함을 보장할 수 있습니다만

`ios_base::sync_with_stdio(false);` 코드를 추가하면서

동기화가 비활성화 되기 때문에

`멀티 쓰레드 환경에서는` 출력 순서를 보장할 수 없게 되는 것입니다!

그리고 버퍼가 분리되었기 때문에,

cin과 scanf, getchar 등을 같이 사용하면 안되고

cout과 print, puts, putchar 등을 같이 사용하면 엉뚱한 결과가 나올 확률이 높기 때문에

사용하면 안 됩니다..

## cin.tie(null);

결론부터 말하자면

`cin.tie(null);`은

cin과 cout의 묶음을 풀어주는 건데요

기본적으로 cin과 cout은 묶여있고

묶여있는 스트림들은 한 스트림이 다른 스트림에서 각 IO 작업을 진행하기 전에

자동으로 버퍼를 비워줌을 보장합니다

예시를 들어보자면

```cpp
cout << "이름을 입력하세요: ";
cin >> name;
```

위 경우, cin과 cout이 묶여있기 때문에

이름을 입력하기 전에, "이름을 입력하세요: " 구문이 먼저 출력될 것입니다.

하지만, `cin.tie(null);` 코드를 추가한다면

cin과 cout의 묶음이 풀리면서

"이름을 입력하세요: " 구문이 출력되지도 않았는데

먼저 이름을 입력받는 경우가 발생할 수 도 있는 것입니다!!

이는 cout이 기본적으로 버퍼에 추가되고, 바로 지워지지 않기 때문입니다..

(출력 명령을 내리거나 버퍼가 가득 찼을 경우에만 버퍼를 비우고 출력함)

따라서, `cin.tie(null);` 코드를 추가했고, name을 입력받기 전에 "이름을 입력하세요: " 구문을 먼저 보고 싶다면

cout으로 "이름을 입력하세요: " 를 출력할 때 버퍼를 비워줘야 합니다

## 결론

알고리즘 문제를 풀 때는

보통 싱글 쓰레드 환경이기 때문에

- `cin.sync_with_stdio(false);` 코드를 추가해줘도 결과에 영향이 없고

- C와 C++ 버퍼를 분리하기 때문에 속도는 빨라지고

- 이 때 C 스타일의 입출력문을 혼용해선 안된다!

마찬가지로, 알고리즘 문제를 풀 때는

화면에 바로 보이는 것이 중요하지 않으므로

- 입력과 출력을 여러 번 번갈아가며 반복해야 하는 경우는 필수적으로

- `cin.tie(null);` 코드를 추가하여

- cout과 cin의 묶음을 풀어줘야 한다!

### 비고

추가적으로

`endl` 구문은

개행 문자 출력과 함께 출력 버퍼를 비우는 역할까지 같이 하기 때문에

딜레이가 발생하니까

알고리즘 문제를 풀 때는 실행 속도를 높이기 위해 C 스타일의 `"\n"`을 통해 개행을 하도록 하는 것~

🔗 [Significance of ios_base::sync_with_stdio(false); cin.tie(NULL); :: stackoverflow](https://stackoverflow.com/questions/31162367/significance-of-ios-basesync-with-stdiofalse-cin-tienull)

🔗 [추가 설명 및 다른 언어 빠른 입출력 방법 :: stackoverflow](https://www.acmicpc.net/board/view/22716)
