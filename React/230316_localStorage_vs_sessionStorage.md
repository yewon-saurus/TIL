# localStorage와 sessionStorage 사용해보기

🔗[[React] 17. localStorage와 sessionStorage 사용해보기 :: 우든이 블로그 tistory](https://shyunju7.tistory.com/37)

브라우저 상에서 데이터를 저장할 수 있는 `webStorage`

## localStorage와 sessionStorage

두 가지 방법 모두 애플리케이션 전역에 접근 가능하다는 공통점이 있는데요..

사용 시 주의해야 할 점은, storage에 저장된 데이터는 모두 `문자열만 사용 가능`하기 때문에 -> 다른 타입의 데이터를 사용할 때는 JSON 형태로 읽고 써야 한다는 것입니다..

두 가지 방법의 차이점은

저장되는 데이터의 범위가 다르다는 점입니다..

- localStorage는 동일한 pc 안에서 동일한 브라우저를 사용했을 때에 사용

    - 즉, 데이터를 직접 삭제하지 않는 한 브라우저를 닫아도 저장된 데이터를 불러올 수 있다.

- **반대로** sessionStorage는 브라우저 창이 닫히면 세션이 종료되면서 storage에 저장된 데이터도 소멸

## localStorage와 sessionStorage API

localStorage와 sessionStorage 두 가지 모두, `setItem(key, value)` 형태로 데이터를 store에 저장하고

`getItem(key)`를 사용하여 저장된 데이터를 store에서 가져올 수 있습니다..

```js
localStorage.setItem('key', value);
localStorage.getItem('key');
```

또한, 아래 코드를 사용하여 저장된 키와 데이터를 일부 또는 모두 삭제할 수 있답니다..

```js
localStorage.removeItem('key');
localStorage.clear();
```

그 외에 `localStorage.length` 라든지 유용한 것들이 있답니다..

# 사용 예

```js
import React, { useState } from "react";

const LocalStorageComponent = () => {
  const [userName, setUserName] = useState("");
  const [check, setCheck] = useState(false);

  const saveData = () => {
    const userObj = { name: userName };
    window.localStorage.setItem("userName", JSON.stringify(userObj));
  };

  const callData = () => {
    setCheck(true);
  };

  const onChange = (e) => {
    setUserName(e.target.value);
    setCheck(false);
  };
  return (
    <div>
      <input
        name="userName"
        value={userName}
        onChange={onChange}
        placeholder="이름을 입력하세요!"
      />
      <button onClick={saveData}>저장하기</button>
      <button onClick={callData}> 불러오기</button>

      {check ? <p>{window.localStorage.getItem("userName")}</p> : <> </>}
    </div>
  );
};

export default LocalStorageComponent;
```

