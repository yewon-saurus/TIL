# Hook의 개요

- Hook은 React 버전 16.8부터.. React의 요소로 새로 추가 되었습니다

- Hook을 이용하여 기존 Class 바탕의 코드를 작성할 필요 없이, 상태 값과 여러 React의 기능을 사용할 수 있습니다

```js
import React, { useState } from 'react';

function Example() {
  // "count"라는 새 상태 변수를 선언합니다
  const [count, setCount] = useState(0);

  return (
    <div>
      <p>You clicked {count} times</p>
      <button onClick={() => setCount(count + 1)}>
        Click me
      </button>
    </div>
  );
}
```

- 여기서 useState가 바로 Hook 이라는데요..

- Hook을 호출해, 함수 컴포넌트 안에 state를 추가한 거랍니다

    - 이 state는 컴포넌트가 다시 렌더링 되어도

    - 그대로 유지될 것

- useState는 현재의 state 값과, 이 값을 업데이트 하는 함수를 쌍으로 제공하는 것.. 기억하고 있죠?

    - 우리는 이 함수를 이벤트 핸들러나 다른 곳에서 호출할 수 있습니다

    - 이것은 class의 this.setState와 거의 유사하지만, 이전 state와 새로운 state를 합치지 않는다는 차이점이 있죠

```js
function ExampleWithManyStates() {
  // 상태 변수를 여러 개 선언했습니다!
  const [age, setAge] = useState(42);
  const [fruit, setFruit] = useState('banana');
  const [todos, setTodos] = useState([{ text: 'Learn Hooks' }]);
  // ...
}
```

- 이렇게 하나의 컴포넌트 내에서.. State Hook을 여러 개 사용할 수도 있구요

## 그래서 Hook이 뭐라구요?

- Hook은 함수 컴포넌트에서

    - React state와 생명주기 기능(lifecycle features)을 "연동(hook into)" 할 수 있게 해주는 함수 입니다

- Hook은 class 안에서는 동작하지 않습니다

    - 대신 class 없이 React를 사용할 수 있게 해주는 것..

    - 하지만 이미 짜놓은 컴포넌트를 모조리 재작성하는 것은.. 비추천이고요

        - 앞으로 새로 작성하는 컴포넌트 부터는 Hook을 이용하면 된다는 거죠

- React는 useState 같은 내장 Hook을 몇 가지 제공한답니다

    - 컴포넌트 간에 상태 관련 로직을 재사용하기 위해 Hook을 직접 만들 수도 있대요

- 내장 Hook

    - State

    - Effect

    - Context

    - ...

## Hook 사용 규칙

- Hook은 그냥 JavaScript 함수이지만, 두 가지 규칙을 준수해야 합니다

    - 1. 최상위(at the top level)에서만 Hook을 호출해야 합니다

        - 반복문, 조건문, 중첩된 함수 내에서 Hook을 실행하지 마세요
    
    - 2. React 함수 컴포넌트 내에서만 Hook을 호출해야 합니다

        - 일반 JavaScript 함수에서는 Hook을 호출하면 안돼안돼~

        - Hook을 호출할 수 있는 곳이 딱 한 군데 더 있는데요.. 바로 직접 작성한 custom Hook 내 입니다

## 검색해볼래요 - 키워드 정리

- useEffect, clean-up function
- useContext
- ❔ useReducer, dispatch
- useMemo
- useCallback
- useRef
- custom hook

# References

🔗[Hook의 개요 :: reactjs.org](https://ko.reactjs.org/docs/hooks-intro.html)