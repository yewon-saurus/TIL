# React JS에서의 명명 규칙

>🔗 [Naming Conventions in React JS | Upbeat Code](https://www.upbeatcode.com/react/react-naming-conventions/)

A well-named file or folder can help you and other developers find and understand your code more quickly.

- 잘 naming 된 파일 또는 폴더를 사용하면

- 사용자 및 다른 개발자가 코드를 더 빨리 찾고, 이해할 수 있겠죠?

## 가장 일반적인 세 가지 명명 규칙

1. 파일 이름에는 카멜, 구성 요소 이름에는 파스칼

    - 카멜 낙타에요 알죠?

    - 파스칼은 카멜과 유사한데, 첫 문자도 대문자로 쓰는 것

2. 파일명은 케밥, 컴포넌트 명은 파스칼

    - 케밥

        - 단어와 단어 사이를 `-`로 구분

        - ex) kebab-case

3. 파일 이름과 구성요소 이름 모두에 대한 파스칼

.
.
.

아하!

React의 컴포넌트는

항상 `파스칼 케이스`를 사용하는구나

```js
const appContainer = <AppContainer />
```

- In addition, the component instance should always be camel-cased.

    - 아하! 그리고 컴포넌트 인스턴스는 항상 카멜 로 하나보네요~

- 아무튼, `컴포넌트 - 파스칼` 외에는..

- 함께 작업하는 사람들과 합의 하에.. 취향껏 정해서 쓰는 것 같네요
