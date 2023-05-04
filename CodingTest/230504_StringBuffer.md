# StringBuffer

StringBuffer는 문자열을 추가하거나 변경 할 때 주로 사용하는 자료형 이랍니다..

StringBuffer의 메서드들을 살펴보면서 StringBuffer의 사용법에 대해 알아봅시다..

## append

StringBuffer 객체를 생성하고 문자열을 생성하는 예제

```java
StringBuffer sb = new StringBuffer();  // StringBuffer 객체 sb 생성
sb.append("hello");
sb.append(" ");
sb.append("jump to java");
String result = sb.toString();
System.out.println(result);  // "hello jump to java" 출력
```

아하.

StringBuffer 자료형은 append 메서드를 사용하여 계속해서 문자열을 추가해 나갈 수 있다.

음 그리고 `toString()` 메서드를 이용해서 String 자료형으로 변경할 수 있습니다..

그리고! StringBuffer 자료형은 String 자료형보다 무거운 편에 속한다.

`new StringBuffer()`로 객체를 생성하는 것은 일반 String을 사용하는 것보다 메모리 사용량도 많고, 속도도 느리다.

📌 따라서 문자열 추가나 변경 등의 작업이 많을 경우에는 StringBuffer를, 문자열 변경 작업이 거의 없는 경우에는 그냥 String을 사용하는 것이 유리하답니다.

# 그런데 잠깐! `StringBuilder`

StringBuffer와 비슷한 자료형으로, StringBuilder가 있다.

StringBuffer의 사용법은 StringBuffer의 사용법과 동일하다.

```java
StringBuilder sb = new StringBuilder();
sb.append("hello");
sb.append(" ");
sb.append("jump to java");
String result = sb.toString();
System.out.println(result);
```

StringBuffer는 멀티 스레드 환경에서 안전하다는 장점이 있고 StringBuilder는 StringBuffer보다 성능이 우수한 장점이 있다.

따라서 동기화를 고려할 필요가 없는 상황에서는 StringBuffer 보다는 StringBuilder를 사용하는 것이 유리하다.

## insert

insert 메서드

특정 위치에 원하는 문자열을 삽입할 수 있다.

```java
StringBuffer sb = new StringBuffer();
sb.append("jump to java");
sb.insert(0, "hello ");
System.out.println(sb.toString());
```

> hello jump to java

## substring

substring 메서드는 String 자료형의 substring 메서드와 동일하게 동작한다.

```java
StringBuffer sb = new StringBuffer();
sb.append("Hello jump to java");
System.out.println(sb.substring(0, 4));
```

> Hell

아!

`substring(시작위치, 끝위치)`와 같이 사용하면 StringBuffer 객체의 시작위치에서 끝위치까지의 문자를 뽑아낸다..
