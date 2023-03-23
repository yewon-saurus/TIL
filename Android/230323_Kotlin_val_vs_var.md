# Kotlin - val, var의 차이점

🔗[Kotlin - val, var의 차이점 :: JoJo_DevStory님 velog](https://velog.io/@jojo_devstory/Kotlin-val-var%EC%9D%98-%EC%B0%A8%EC%9D%B4%EC%A0%90)

코틀린은 JVM에서 동작하는 프로그래밍 언어로, 2011년 7월, JetBrain사가 공개하였답니다

2017년 구글 I/O에서 공식 언어로 지정된 후, 근래 신규로 개발하는 안드로이드 앱은 대부분 코틀린으로 개발되는 추세이며?!

기존에 자바로 개발하던 앱들도 코틀린으로 전환하고 있다는데요?!

이런 추세에 맞춰 구글 레퍼런스 API 문서에서도, 예제 코드에 코틀린이 앞에 오고 자바가 뒤로 밀려난 모습도..

기존의 자바보다 장점이 많고, 자바 API의 저작권을 소유한 오라클에 종속되지 않기 때문에.. 구글에서도 코틀린을 선택했다고 볼 수도 있겠습니다

## val, var의 차이

코틀린은 자바와 달리 변수 선언 시 val과 var를 사용하여 타입선언 없이 바로 값을 할당할 수 있습니다

(물론 타입 별도 지정도 가능함)

val과 var는 변수의 시작을 알리면서 변수가 불변(immutable type)인지 가변(mutable type)인지를 나타냅니다

공통적으로 초기화 시 값을 할당하지 않는다면 -> **반 드 시 type을 명시해야 합니다**

하지만 컴파일러가 변수 타입을 추론할 수 있는 경우라면 타입을 생략해도 OK 랍니다..

### val

- val로 지정된 불변 타입 변수는 초기에 값을 할당하면 나중에 값을 변경할 수 없으며 값을 변경하게 되면 컴파일 에러가 발생합니다.

    - 즉, 값을 초기화만 가능하고 변경은 불가능

    - Java에서는 final과 같다고 볼 수 있습니다.

- val은 한 번만 초기화 되며 값을 변경할 수 없지만, 컴파일러가 코드 문맥을 확인 시 val 변수가 한 번만 초기화 되는 것이 맞다면 개발자가 상황에 따라 val를 여러 값으로 초기화(할당)할 수 있습니다.

- val은 초기화 후 값을 변경이 불가능한 것이 맞습니다..

    - 하지만 변수의 참조가 가리키는 객체의 내부 값은 변경이 가능합니다.

네?

- val은 value의 약어

```kotlin
fun main(args: Array<String>){
  // 1. val : value의 약어이며 변경 불가능(immutable)한 변수, 초기화만 가능
  val name = "Kotlin"
  //1-1. 위에서 이미 값이 할당 되었기 때문에 아래 코드처럼 값 할당 불가
  name = "Java"
  
  //2. 타입 지정 가능, 다만 1번처럼 컴파일러에서 타입이 추론 가능한 경우 생략 가능
  val name2: String = "Swift"
  //2-1. 초기화시 값을 할당하지 않을시엔 반드시 타입을 지정해야함
  val name2: String
  name2 = "Swift"
  
  //3. 코드 문맥에 따라 val 변수가 1번만 초기화 되는것이 맞다면 여러 값을 초기화(할당) 가능
  val name3: String 
  
  if (isSuccess()){ 
    name3 = "Anroid" 
  }else{ 
    name3 = "iOS"
  }
  println("name3 : $name3")
  
  //4. 변수의 참조가 가리키는 객체의 내부 값은 변경이 가능
  val nameArray = arrayListOf("Kotlin")
  nameArray.add("Java")
  println("nameArray : $nameArray")
}
```

### var

- var로 지정된 가변 타입 변수는 **초기화 후 값을 변경이 가능합니다.**

    - 하지만, 다른 타입의 값을 넣을 수는 없습니다. (아무래도..)

        - ex) 처음에 String 타입으로 초기화를 한 뒤 int 타입의 값을 넣을 수는 없습니다.

    - 그렇다고 해당 변수를 뒤에서 Int 타입으로 재정의 한다면 타입 미스매치(Type missmatch) Error가 발생합니다.

    - 이미 정의된 타입을 변경하려면, 자바와 같이 **형변환**을 해야합니다.

```kotlin
fun main(args: Array<String>){
  //1. 초기화 후 값 변경 가능
  var name1 = "kotlin" 
  name1 = "java"
  println("name1 : $name1") //출력 : java
  
  //2. 초기화 시 타입을 지정 했다면 다른 타입의 값을 넣는 것은 불가능
  var name2 = "kotlin" 
  name2 = 77 //Type mismatch 에러 발생
}
```
