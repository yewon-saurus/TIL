# 타입

https://yamoo9.gitbook.io/typescript/types/primitives

## primitive 타입

명시적으로

```ts
let product_id: number = 123456;

let product_name: string = 'VR 클래스';

let is_waterprofing: boolean = false;
```

아~

설정된 데이터 타입이 아닌 데이터 타입을 할당하려 한다면? TypeScript는 컴파일 과정에서, 오류를 출력해 사용자에게 알립니다.

## any 타입

동적 형 지정 언어인 JavaScript는 선언된 변수에 어떤 값이든 재할당이 가능합니다.

그런데? TypeScript는 명시적으로 데이터 유형을 설정해 사용하는 정적 형 지정 언어로, 타입을 지정해 사용하는 것이 권장됩니다.

하지만, 애플리케이션 개발 시, 어떤 타입을 할당해야 할 지 알지 못하는 경우가 있을 수 있답니다..

- 외부 라이브러리나 동적 콘텐츠를 사용할 경우 라든지요

이런 경우 어떤 타입도 할당 가능하도록 `any`를 설정할 수 있습니다.

JavaScript는 기본적으로 변수에 any가 할당된 것과 같다고 생각해 보세요!(자동으로 형 변환이 이루어지죠?)

```ts
let product_id: any = 123456;

product_id = 'hi hello'; // any 유형이 설정되었으므로, 어떤 유형도 값으로 할당 가능
```

다음과 같이 변수 선언과 초기화 과정에서 값을 할당하지 않으면, 암시적으로 `any` 타입이 지정된답니다.

```ts
let product_id;

product_id = 123456;
product_id = 'hi hello';
```

## array 타입

명시적 타입 지정 없이 코드를 아래와 같이 작성하면, TypeScript는 컴파일 과정에서 다음과 같은 오류를 출력합니다.

```ts
let members = ['이권', '감장겸', '장도일'];

// [오류]
// [ts] 'number[]' 형식은 'string[]' 형식에 할당할 수 없습니다.
//      'number' 형식은 'string' 형식에 할당할 수 없습니다.
// let members: string[]
members = [9, 13, 26];
```

오류가 발생한 이유는..

암시적으로 members 변수에 설정된 데이터 타입이 string[] 이기 때문입니다.

string 타입만으로 채워진 초기 배열과 달리, members = [9, 13, 26] 구문은 number 타입으로만 데이터를 채워, 문제가 된다고 경고합니다.

```ts
let members:string[] = ['이권', '감장겸', '장도일'];
```

흠..

만약 복합적으로 어떠한 데이터 타입도 아이템으로 설정할 수 있는 배열이 필요하다면, 다음과 같이 명시적 타입 선언을 수행할 수 있습니다. `any`는 어떤 데이터 타입도 배열 아이템으로 설정 가능함을 말합니다.

```ts
let members:any[] = [{name: '이권'}, '감장겸', ['장도일']];
```

```ts
// 오직 숫자 아이템만 허용
let nums:number[] = [100, 101, 102];

// 오직 문자 아이템만 허용
let strs:string[] = ['ㄱ', 'ㄴ', 'ㄷ'];

// 오직 불리언 아이템만 허용
let boos:boolean[] = [true, false, true];

// 모든 데이터 타입을 아이템으로 허용
let anys:any[] = [100, 'ㄴ', true];

// 특정 데이터 타입만 아이템으로 허용
let selects:(number|string)[] = [102, 'ㅇ'];
```

응? `|` 이건 뭐죠?

### (잠깐!) Type Guard

Type Guard를 통해 컴파일러가 타입을 예측할 수 있도록 타입을 좁혀 주어서(narrowing) 좀 더 `type safety`함을 보장할 수 있습니다.

## tuple 타입

튜플, 터플

tuple 타입은 JavaScript에서는 지원하지 않는 데이터 타입이지만, TypeScript에서는 배열 타입을 보다 특수한 형태로 사용할 수 있는 `tuple` 타입을 지원합니다.

tuple에 명시적으로 지정된 형식에 따라 아이템 순서를 설정해야 되고, 추가되는 아이템 또한 tuple에 명시된 타입만 사용 가능합니다.

```ts
let book__name_price:[string, number] = ['카밍 시그널', 13320];

// [오류]
// [ts] '[number, string]' 형식은 '[string, number]' 형식에 할당할 수 없습니다.
//      'number' 형식은 'string' 형식에 할당할 수 없습니다.
// let book__name_price: [string, number]
book__name_price = [13320, '카밍 시그널'];

// [오류]
// [ts] 'false' 형식의 인수는 'string | number' 형식의 매개 변수에 할당될 수 없습니다.
book__name_price.push(false);
```

## enum 타입

아아.. 열거형 데이터라는 거죠

멤버라 불리는 명명된 값의 집합을 이루는 자료형으로 기억하기 어려운 숫자 대신 친숙한 이름으로 접근/사용하기 위해 활용할 수 있습니다.

열거된 각 멤버는 별도의 값이 설정되지 않은 경우 기본적으로 0부터 시작합니다.

아래 코드에서 `sarha` 변수에 할당된 값은 3 입니다.

```ts
enum Team {
  Manager,   // 0
  Planner,   // 1
  Developer, // 2
  Designer,  // 3
}

let sarha:number = Team.Designer; // (enum member) Team.Designer = 3
```

그래요.. 그렇군요

enum에 설정된 아이템에 값을 할당할 수도 있습니다.

값이 할당되지 않은 아이템은 이전 아이템의 값에 `+1`된 값이 설정됩니다.

```ts
enum Team {
  Manager   = 101,
  Planner   = 208,
  Developer = 302,
  Designer, // 302 + 1
}

let yamoo9:number = Team.Manager; // (enum member) Team.Manager = 101
let sarha:number = Team.Designer; // (enum member) Team.Designer = 303
```

자연스럽네요..

그리고 이 숫자 값을 통해 enum 값의 멤버 이름을 도출할 수도 있다는 점이 매우 편리한 기능입니다.

```ts
let role:string = Team[302]; // 'Developer'
```
