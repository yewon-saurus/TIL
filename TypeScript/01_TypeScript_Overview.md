# TypeScript Overview

- https://slides.com/woongjae/deck-8
- https://slides.com/woongjae/deck-8-14

🔗[TypeScript Guidebook](https://yamoo9.gitbook.io/typescript/introduction)

타입스크립트는 프로그래밍 언어 입니다. (그렇겠죠)

타입스크립트는 compiled language 인데, 전통적인 compiled language와는 다른 점이 많습니다.

- 그래서 `Transpile` 이라고도 한다네요

자바스크립트는 interpreted language 였답니다.

와! 그리고 vscode에서 typescript 지원이 잘 된다네요

vscode도 typescript로 쓰여졌대요

# TypeScript Basic Types

JavaScript의 기본 자료형을 포함합니다. (superset)

- ECMAScript 표준에 따른 기본 자료형은 6가지

    - Boolean

    - Number

        - JavaScript와 마찬가지로, TypeScript의 모든 숫자는 부동 소수점 값

        - TypeScript는 16진수 및 10진수 리터럴 외에도, ECMAScript 2015에 도입된 2진수 및 8진수를 지원합니다.

    - String

        - JavaScript와 마찬가지로, `'`나 `"`로 감싸서..

        - Template String

            - 행에 걸쳐 있거나, 표현식을 넣을 수 있는 문자열

            - backtick ` 으로 감싸서..

    - Null

        - 'undefined'와 'null'은 각각 고유한 타입이랍니다.

        - 'void'와 마찬가지로, undefined와 null은 그 자체로는 쓸모가 없답니다.

    - Symbol

        - 이거 뭐죠?! 처음 보는데요

        - ECMAScript 6 에 추가

        - 고유하고 수정 불가능한 값으로 만들어 줍니다.

        - 주로 접근을 제어하는데 쓰는 경우가 많았습니다.

    - Array: Object 형

그리고!

프로그래밍을 도울 몇 가지 타입이 더 제공됩니다.

- Any

    - 어떤 타입이어도 상관 없는 타입

    - **이걸 최대한 쓰지 않는 게 핵심**

        - 왜냐면 컴파일 타임에 타입 체크가 정상적으로 이루어지지 않게 되거든요!!
    
    - 그래서 컴파일 옵션 중에는, any를 쓰면 오류라고 알려주는 옵션도 있습니다

        - noImplictAny

- Void

    - 타입이 없는 상태

    - 'any'와 반대의 의미

    - 'void'라고 쓴답니다.

    - 함수의 리턴이 없을 때 주로 사용합니다. 그 외에는 사용할 일 거의 없습니다.

- Never

    - 리턴에 주로 사용

    - error, fail, 무한루프 이런거에 사용한다..?

- Enum

- Tuple: Object 형

    - 배열인데, 타입이 한 가지가 아닌 경우

### null in JavaScript

- null 이라는 값으로 할당된 것을 null 이라고 합니다.

- 무언가가 있는데, 사용할 준비가 덜 된 상태

- null 이라는 타입은 null 이라는 값만 가질 수 있습니다.

- 런타임에서 typeof 연산자를 이용해서 알아내면, object 입니다.

### undefined in JavaScript

- 값을 할당하지 않은 변수는 undefined 라는 값을 가집니다.

- 무언가가 아예 준비가 안 된 상태

- object의 property가 없을 때도 undefined 입니다.

- 런타임에서 typeof 연산자를 이용해서 알아내면, undefined 입니다.

# var, let, const

- var

    - ES5

    - 변수의 유효 범위: 함수 스코프

    - 재선언 가능

- let, const

    - ES6

    - 변수의 유효 범위: 블록 스코프(친숙)

    - 재선언 불가

음.. 그리고 var 보다는 let, const를 쓰나보죠?


잠깐! 갑자기 알아본 지식

- 호이스팅

    - 호이스팅이 뭐였죠?.. 인터프리터가 변수와 함수의 메모리 공간을 선언 전에 미리 할당하는 것을 의미.. 코드가 실행하기 전 변수선언/함수선언이 해당 스코프의 최상단으로 끌어 올려진 것 같은 현상.. 자바스크립트 함수는 실행되기 전에 함수 안에 필요한 변수값들을 모두 모아서 유효 범위의 최상단에 선언한다..

    - 🔗[자바스크립트의 호이스팅 :: velog](https://velog.io/@eassy/%EC%9E%90%EB%B0%94%EC%8A%A4%ED%81%AC%EB%A6%BD%ED%8A%B8%EC%9D%98-%ED%98%B8%EC%9D%B4%EC%8A%A4%ED%8C%85)

# Type assertions

형변환과는 다른 개념인데요

형변환은 실제 데이터 구조를 바꿔주는 녀석이라면?

타입 어설션은 '타입이 이것이다'라고 컴파일러에게 알려주는 것을 의미

그래서 행동에 대해서 작성자가 100% 신뢰하는 것이 중요합니다.

```ts
let somValue: any = "this is a String";

let strLength: number = (<string>someValue).length;
let strLength: number = (someValue as string).length;
```

음..

assertion 이라는게

프로그램의 특정 지점에 위치한 어썰션은, 해당 지점에서 개발자가 반드시 참(true)이어야 한다고 생각하는 사항을 표현한 논리식이다.

# Type alias

타입 별칭(별명)

인터페이스랑 비슷해 보입니다..

기타 직접 작성해야하는 타입을 다른 이름으로 지정할 수 있습니다?

만들어진 타입의 refer로 사용하는 것이지, 타입을 만드는 것은 아닙니다

```ts
type MyStringType = string;

const str = 'World';

let myStr: MyStringType = 'hello';

myStr = str;
```

..?

