# Java 문자열 자르기 - substring

`substring()`

java.lang.String 클래스의 substring() 메소드..

문자열의 특정 부분을 잘라내는 데 사용하죠

```java
public String substring(int startIndex);
// start index부터 끝까지의 문자열을 잘라서 리턴
// 잠깐! index는 0부터 시작한다는 점을 잊지 마세요

public String substring(int startIndex, int endIndex);
// start index부터, end index(얘는 불포함)까지의 문자열을 리턴
```

```java
public class SubstringExample {
    public static void main(String[] args) {
 
        String str = "Hello";
 
        System.out.println(str.substring(2)); // "llo"
        System.out.println(str.substring(5)); // ""
        System.out.println(str.substring(-1)); // StringIndexOutOfBoundsException
        System.out.println(str.substring(6)); // StringIndexOutOfBoundsException
 
    }
}
```

```java
public class SubstringExample {
    public static void main(String[] args) {
 
        String str = "Hello";
 
        System.out.println(str.substring(2, 4)); // "ll"
        System.out.println(str.substring(2, str.length())); // "llo"
 
    }
}
```
