# Context API

Context란? React 컴포넌트 사이에 어떠한 값을 공유할 수 있게 해주는 기능이다. 주로 Context는 전역적(Global)으로 필요한 값을 다룰 때 사용한다. (그러나, 꼭 전역적일 필요는 없다..) Context를 단순히 "React 컴포넌트에서 props가 아닌 또 다른 방식으로 컴포넌트 간에 값을 전달하는 방법이다"라고 접근을 해보자.

props로만 데이터를 전달하면, 여러 컴포넌트를 거쳐 연덜아 props를 설정해주어야 하기 때문에, 불편하고 실수할 가능성이 높아진다. (LiQuest에서의 추억..) 그런 코드를 **props drilling**이라고 부른다. 컴포넌트를 한 두개 정도만 거치면 감당 가능하겠지만, 3개, 4개 이상을 거쳐서 전달하게 된다면 너무 불편할 것이다. (네.. 맞아요) props가 어디서 전달되어져 오는건지 쉽게 파악한다든지, state의 통일성을 맞추려다보면 또 여러 컴포넌트들을 수정해야하는 귀찮은 상황을 피하기 위해, 쓰면 좋다는 거겠지?

## Context 사용법

React package에서 `createContext`라는 함수를 불러와서 만들 수 있다.

```jsx
import { createContext } from 'react';
const MyContext = createContext();
```

```jsx
function App() {
  return (
    <MyContext.Provider value="Hello World">
      <GrandParent />
    </MyContext.Provider>
  );
}
```

Context 객체 안에는 `Provider`라는 컴포넌트가 들어있는데, 그 컴포넌트 간에 공유하고자 하는 값을 `value`라는 props로 설정하면 자식 컴포넌트들에서 해당 값에 바로 접근할 수 있다.

```jsx
import { createContext, useContext } from 'react';

function Message() {
  const value = useContext(MyContext);
  return <div>Received: {value}</div>;
}
```

`useContext`라는 Hook을 이용하면 Context에 넣은 값에 바로 접근할 수 있다. 그러니까, `return <div>Received: Hello World<div>`가 나타나게 되는 거겠지?

```jsx
const MyContext = createContext('default value');
```

이렇게 하면 기본값을 설정할 수가 있고요!!

## 값과 업데이트 함수를 두 개의 Context로 분리하기

만약 Context에서 관리하는 상태가 빈번하게 업데이트 되지 않는다면, 상태를 공유하는 컴포넌트가 많은 상황에서도 충분히 괜찮다. 그러나, 만약에 상태가 빈번하게 업데이트 된다면, 성능적으로 좋지 않다. (그럴 것 같네요) 실제로 변화가 반영되는 곳은 `Component1` 뿐인데, `Component2`도 같이 리렌더링 된다면 말이다. 이럴 때는 **Context를 하나 더 만드는 방법**을 떠올려 보자!

예를 들면, `ConterContext`라는 컴포넌트가 있었을 때, 이것을 `ConterValueContext`와 `CounterActionsContext`로 분리해주는 것이다. 그리고 두 Provider를 모두 사용해 준다. 커스텀 Hook 또한 두 개로 분리한다.

상태를 다루는 Context를 활용하는 과정에서, 여러 업데이트 함수가 들어있는 `actions` 객체를 선언하여 별도의 Context에 넣어주는 방식으로 구현하는 방법, `useReducer`를 통해서 상태 업데이트를 하도록 구현하고 `dispatch`를 별도의 Context로 넣어주는 방법 등이 있다고 한다.

- useReducer ?

위와 같은 방법은 **배열이나 객체**를 다룰 때에도 동일하다는 점도 기억하자.

## 꼭 전역적이어야 할 지

Context에서 다루는 값은 꼭 전역적일 필요는 없다. Context는 재사용성이 높은 컴포넌트를 만들때도 매우 유용하다.

'상태 관리 라이브러리'와 Context는 완전히 별개의 개념임을 이해해야 한다. Context는 전역 상태 관리를 할 수 있는 수단일 뿐이고, 상태 관리 라이브러리는 상태 관리를 더욱 편하고, 효율적으로 할 수 있게 해주는 기능들을 제공하는 도구이다. '전역 상태 관리 라이브러리'는 결국 상태 관리를 조금 더 쉽게 하기 위해서 사용하는 것이며 취향에 따라 선택해 사용하면 된다고 한다.

- 전역 상태 관리 라이브러리
  - Redux
  - MobX
  - Recoil
  - Jotai
  - Zustand
