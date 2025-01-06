# Zustand.md

[Zustand 핵심 정리](https://www.heropy.dev/p/n74Tgc)

- 작고 빠르며 확장 가능한 React 프로젝트에서 사용하는 상태 관리(store) 라이브러리

## store

- store: 애플리케이션의 여러 상태(state)를 중앙에서 관리하는 패턴
- 컴포넌트 간 데이터를 쉽게 공유 가능

대부분의 애플리케이션은

- App을 기준으로 하는 여러 하위 컴포넌트로 구성되어 있는데요..
- Props Drilling: 속성(data)이 여러 컴포넌트를 관통하는 것 같다고 해서 붙은 이름 (드릴 -> 관통 관통 관통)
- store를 사용해서, 컴포넌트 간 공유할 데이터를 중앙에서 관리할 수 있답니다..
    - 데이터를 전달하는(자기는 그 데이터를 쓸 일도 없으면서) 중간 단계 컴포넌트가 필요치 않으므로, 컴포넌트 간 결합도를 낮추고 유지보수를 쉽게 만듭니다.

## 사용 방법

### 설치

```shell
npm i zustand
```

### create

```jsx
import { creat } from 'zustand';
export const useBlablaStore = create((set, get) => {
    return {
        상태: 초깃값,
        액션: 함수,
    }
});
```

- create 함수로 스토어 생성
- 속성-State
- 메소드-Action
- useBlablaStore: `use` 접두사와 `Store` 접미사로 명명해 각 컴포넌트에서 사용 (즉, 여기에선 Blabla가 이름인 것이죠)

```ts
import { create } from 'zustand'
export const use이름Store = create((set, get) => {
  return {
    상태: 초깃값,
    액션: () => {
      const state = get()
      const { 상태 } = state
      set({ 상태: 상태 + 1 })
    }
  }
})
```

- `get` 함수: 상태와 액션을 가진 스토어 객체(`state`)를 얻을 수 있습니다.
- `set` 함수: 변경할 상태를 속성으로 포함한 객체를 전달해 상태를 변경할 수 있습니다.

> 이렇게 쓸 수도 있다 - set 콜백 사용

```ts
import { create } from 'zustand'
export const use이름Store = create(set => {
  return {
    상태: 초깃값,
    액션: () => {
      set(state => ({ 상태: state.상태 + 1 }))
    }
  }
})
```

- get 함수를 사용하지 않고도 바로 스토어 객체(`state`)를 얻어냈습니다.
- 변경할 상태를 속성으로 포함한 객체를 콜백에서 반환

### 데이터 사용

```ts
import { use이름Store } from '~/store/스토어'
export default function 컴포넌트() {
  const 상태 = use이름Store(state => state.상태)
  const 액션 = use이름Store(state => state.액션)
  return (
    <>
      <h2>{상태}</h2>
      <button onClick={액션}>+</button>
    </>
  )
}
```

> `state => state.어쩌구` 콜백 없이 store hook을 호출하면 '스토어 객체'를 얻을 수 있긴 합니다만..

```ts
import { use이름Store } from '~/store/스토어'
export default function 컴포넌트() {
  const 스토어 = use이름Store()
  return (
    <>
      <h2>{스토어.상태}</h2>
      <button onClick={스토어.액션}>+</button>
    </>
  )
}
```

- 사용하지 않는 state가 변경되었을 때에도 컴포넌트가 다시 렌더링되기 때문에, 권장하지 않는 방법입니다.

### 액션 분리

`actions` 객체 안에서 모든 객체 관리 -> 각 컴포넌트에서 필요한 액션만 가져오기 -> good

### 상태 초기화

action에 resetState 함수 추가해 사용하기

### 상태 삭제

- `set` 함수의 두 번째 인수(기본값: `false`)로 `true`를 전달하면, 상태를 병합하지 않고 덮어습니다.
- Lodash의 `omit` 함수는 특정 속성들을 제외한 새로운 객체를 반환합니다.

이를 조합하면, 특정 상태들을 삭제할 수 있습니다.

```shell
npm i lodash-es
npm i -D @types/lodash-es
```

[lodash란?](https://velog.io/@kysung95/%EC%A7%A4%EB%A7%89%EA%B8%80-lodash-%EC%95%8C%EA%B3%A0-%EC%93%B0%EC%9E%90)

### 미들웨어

추가 기능(타입 추론, 중첩 객체 변경 등) 확장

### 상태의 타입 추론 (Combine)

### 액션 안에서 액션 호출하기

### 중첩된 객체 변경 (Immer)

```shell
npm i immer
```

immer는 Immer를 사용하기 위해 설치해야 하는 Zustand의 Peer(또래) Dependency 입니다.

### 상태 구독 (subscribeWithSelector)

- store hook `subscribe` 함수 -> 스토어의 모든 상태 변경을 구독(말하자면, 상태를 감지해 리스너를 호출)합니다.
- `subscribe` 함수의 반환을 호출하면, 구독을 해제할 수 있습니다.

```shell
const listener = (newState, oldState) => {}
const unsubscribe = useCountStore.subscribe(listener)
unsubscribe() // 구독 해제
```

- 특정 상태 변경만 구독하려면, 이때 쓰는 것이 미들웨어 `subscribeWithSelector`

### 스토리지 사용 (Persist)

무려 이를 통해 페이지를 새로고침하거나 다시 방문했을 때에도 상태를 유지할 수 있습니다.

- 스토리지에 저장될 스토어의 고유한 이름을 필수 옵션(name)으로 제공해야 합니다.
- 또한 로컬 스토리지(localStorage)를 기본으로 사용하며, 필요하면 세션 스토리지(sessionStorage)나 커스텀 스토리지를 만들어 사용할 수도 있습니다.

### 개발자 도구 (Devtools)

`devtools` 미들웨어를 사용하면, 개발자 도구가 활성화 됩니다. (Redux DevTools 처럼..)