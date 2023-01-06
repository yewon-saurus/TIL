# 📖 목차

![JSON 객체 vs JSON 배열](#json-객체-vs-json-배열)

![JSON 데이터를 다루기위한 JS 기본 사용법1](#json-데이터를-다루기위한-js-기본-사용법1)

![JSON 데이터를 다루기 위한 JS 기본 사용법2](#json-데이터를-다루기-위한-js-기본-사용법2)

![중첩된 JSON 데이터 다루기](#중첩된-json-데이터-다루기)

![중첩된 JSON 데이터 다루기 - 반복문을 이용한 카테고리 출력](#중첩된-json-데이터-다루기---반복문을-이용한-카테고리-출력)

# JSON 객체 vs JSON 배열

- JSON 만들 줄도 알아야 겠죠~

- JSON 많이 쓰는 이유?

    - 데이터를 전달하고, 교환하고, 저장할 때

    - 가볍고, 텍스트기반, JS 기반 -> 배우기 쉬움!

- JS를 모르면 어려울 수도 있겠죵?

- 어찌됐건~ JS 기반의 어떤 문법에 대해 잘 알고 있다면.. 손쉽게 다룰 수 있을 거구요

- JSON 객체 -> 중괄호 `{}` 사용

- [1] JSON에서 객체란?

    - `key: value`의 한 쌍으로 이루어진, 정렬되지 않은, 속성(property)들의 집합

    - 구분은 `,`로 했죠

        - 여러 개의 속성을 가질 수 있다

    - 문자열은 만드시 큰따옴표`""`로 묶어준다~

```json
{
    "name": "홍길동",
    "age": 20,
    "nationality": "대한민국",
    "hobby": "영화보기"
}
```

- 규칙을 지켜서 JSON 객체를 하나 만들어 봤어요

- [2] `객체 안에 객체`가 들어있는 경우도 있어요

```json
{
    "group1": {
        "name": "홍길동",
        "age": 20,
        "nationality": "대한민국",
        "hobby": "영화보기"
        "company": {
            "cname": "XX원자력발전소",
            "cphone": "00-0000-0000",
            "caddress": "경기도 용인시 어쩌구"
        }
    }
}
```

- 계층적 구조가 가능한 거구나~

- [3] JSON 배열

    - 대괄호 `[]` 사용

    - 역시 여기서도, 콤마 `,`를 사용하여 여러 JSON 객체를 추가 및 구분할 수 있다

    - 배열의 이름이 person이고, 3개의 JSON 객체를 이 배열의 요소로 가지는 JSON 배열을 만들어 보면?

```json
"person": [
    {},
    {},
    {}
]
// 3개 니까 일단 이렇게
```

```json
"person": [
    {
        // 이게 하나의 개객체 인거죠?
        // 중괄호로 묶여있죠?
        "name": "홍길동",
        "age": 20,
        "nationality": "한국"
    },
    {
        "name": "이순신",
        "age": 21,
        "nationality": "한국"
    },
    {
        "name": "Tom",
        "age": 31,
        "nationality": "미국"
    }
]
```

# JSON 데이터를 다루기위한 JS 기본 사용법1

```js
const person = [
    {
        "name": "홍길동",
        "age": 20,
        "nationality": "한국"
    },
    {
        // 작은 따옴표로 감쌈
        '"name": "이순신", "age": 21, "nationality": "한국"'
    },
    {
        "name": "Tom",
        "age": 31,
        "nationality": "미국"
    }
]

console.log(typeof person); // object
console.log(typeof person[0]); // object
console.log(typeof person[1]); // string

console.log(person[0].name + " " + person[0].age + " " + person[0].nationality); // 홍길동 20 한국

console.log(...person); // 전개 연산자 `...`
// 반복이 가능한 객체에 대해, 그.. 애들을 뿌려줌

console.log([...person]); // 배열 // __proto__: Array
console.log({...person}); // 객체 // __proto__: Object
// __proto__ -> 원형을 가리킨다고요?
// 얘 만들어 졌는데.. 너 어디서 왔니? 부모가 누구니? 원형이 뭐니?
// 너를 만들 수 있게 해 준 원형이 뭐니?

console.log([...person].length); // 3
console.log([...person][0].name); // 홍길동

console.log({...person}[1].name); // 이순신

for (let ele of person) {
    // person -> iterable, 즉 반복 가능한 객체 -> 이건 배열이니까 가능이죠?
    // let ele of person[0] 이런건 안되겠죠? 반복이 가능한 객체가 아니니까요
    consolo.log(ele);
}
```

# JSON 데이터를 다루기 위한 JS 기본 사용법2

- 수정

    - 백틱 `

```js
console.log(`홍길동의 이름이 ${person[0].name} 으로 수정되었습니다.`);
```

- `for .. in`

```js
for (let i in person) {
    console.log(i); // 0, 1, 2
}
```

- 이건 배열이라서 index를 출력했는데요

    - 객체면.. key가 나온다네요

# 중첩된 JSON 데이터 다루기

.

# 중첩된 JSON 데이터 다루기 - 반복문을 이용한 카테고리 출력

.