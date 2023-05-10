# TypeScript Overview

- https://slides.com/woongjae/deck-8
- https://slides.com/woongjae/deck-8-14
- https://slides.com/woongjae/deck-8-15

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
