# 리액트 라우터를 활용한 권한별 라우팅 제어

🔗[리액트 라우터를 활용한 권한별 라우팅 제어 :: 김정환 블로그](https://jeonghwan-kim.github.io/dev/2020/03/20/role-based-react-router.html)

라우팅 로직을 만들때.. 매번 들어가는 것이 인증과 인가 이죠?

얘네는 비슷하면서 엄연히 다르답니다..

- 인증 Authentication

    - 사용자를 식별하는 것

- 인가 Authorization

    - 식별된 사용자의 권한을 제어하는 것

인증과 인가에 따라서 분기 처리하는 라우팅 로직을 작성하는 것은..

대부분의 어플리케이션에서 제공되어야 할 필수 기능이죠?

이것은 프레임 웍과 무관해서

비단.. 리액트, 뷰js, 그리고 서버를 만드는 노드js에서도 마찬가지 랍니다..

## 인증과 인가

- 401: Unauthrized (미승인)

- 403: Forbidden (금지됨)

`인증`은 로그인 과정을 거친 뒤 부여하는 작업인데, 로그인 실패 시 서버는 401 코드를 응답하고.. 클라이언트는 로그인 실패 화면을 그립니다.

로그인이 완료된 이후 특정 리소스에 접근할 때, 권한 체크를 하는데요 -> 이것이 `인가` 입니다..

권한이 있으면 리소스를 응답하고

그렇지 않은 경우에는 서버가 403 코드를 응답한다는 거죠..

그러면? 클라이언트는 사용자에게 리소스에 대한 접근 권한이 없다고 피드백 합니다..

## `<Route>` 인터페이스 살펴보기

```jsx
export interface RouteProps {
  component?:
    | React.ComponentType<RouteComponentProps<any>>
    | React.ComponentType<any>
  render?: (props: RouteComponentProps<any>) => React.ReactNode
  path?: string | string[]
  // 생략
}
```

component는 path로 정의한 url 요청이 들어왔을 때 어떤 컴포넌트를 보여줄지 정의하는 속성인데요

`render()` 함수도 이름으로 보면 component와 비슷한 역할을 하는 녀석인데.. '함수'로 되어 있다는 점이 다릅니다..

단, 주의해야 할 것이 있는데

component 속성은 render보다 우선하기 때문에, 두 속성을 동시에 사용하지 말아야 한다는 점이지요

## `<RouteIf>` 권한별 라우팅

`<Route>`를 감싼 컴포넌트를 만들어야 겠다.

비슷하게 사용하지만 권한 정보를 받는 인터페이스를 갖도록 말이죠?

- (아~ 이 분이 만드신 거구나..)

권한에 따라 컴포넌트를 보여줄지 말지 결정하는 역할이므로! RouteIf라고 이름 지으셨다네요

```jsx
const RouteIf = ({ component: Component, ...rest }) => {
  return (
    <Route
      {...rest}
      render={props => {
        /* 권한이 없을 경우 */
        if (true) {
          return <FobiddenPage />
        }

        /* 권한이 있을 경우 */
        if (Component) {
          return <Component {...props} />
        }

        return null
      }}
    />
  )
}
```

render() 함수가 시작할 때.. 권한이 없는 경우를 먼저 검사해서 -> `<FobiddenPage>` 컴포넌트를 반환해 버리는 것이죠..

그러면 아래 컴포넌트를 그리지 않고 '권한 없음' 화면을 그릴 것입니다..

...

## 페이지별 권한 테이블

권한 데이터는 언제, 어디에서 획득할 수 있을까?..

로그인을 마치고 나면 사용자는 인증된 상태이죠?

서버가 사용자를 식별했다는 의미 입니다

서버는 인증된 사용자 모두에게 리소스 접근을 허용하지는 않는다고 합니다..

사용자가 가진 권한에 따라, 허용하거나 차단하거나 하는데요

그렇기 때문에 사용자 별로 권한 정보를 가지고 있어야 하는데,

로그인 후에 이 정보를 조회할 수 있습니다..

로그인 후, 혹은 권한 조회 API를 통해 응답받은 데이터를

아래 myRole 객체에 담으면 이런 모습이 됩니다

```jsx
const myRole = {
  usersPage: ROLE.NONE, // 사용자 관리 화면
  productsPage: ROLE.READ, // 상품 관리 화면
  adPage: ROLE.WRITE, // 광고 관리 화면
  // ...
}
```

화면에 따른 권한값으로 구성된 객체죠?

- 유저 관리 화면(userPage)은 쓰기 권한

- 상품 관리 화면(products)은 읽기 권한

- 광고 관리 화면(adPage)은 권한 없음

이 유저는 그렇다는 것입니다..

...

