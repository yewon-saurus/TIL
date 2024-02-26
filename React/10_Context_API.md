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
