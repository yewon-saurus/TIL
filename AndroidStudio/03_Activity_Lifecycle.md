# 안드로이드 액티비티(Activity) 생명 주기(Lifecycle) 백스택(Backstack)

🔗[안드로이드 액티비티(Activity) 정리하기 - 생명 주기(Lifecycle) 백 스택(Backstack) :: Jungwoon Blog](https://jungwoon.github.io/android/2019/07/15/Activity.html)

Activity

- Android의 대표적인 구성 요소 중 하나인 Activity

- UI를 구성하는 기본 단위 입니다..

Activity의 3가지 상태

- 재개됨 Resumed: 액티비티가 화면 포그라운드에 있고, 포커스를 갖습니다.

- 일시정지됨 Paused: 액티비티 `일부가` 가려진 상태. 이 때는 액티비티가 완전히 살아 있지만(Activity 객체가 메모리에 보관되어 있고, 모든 상태 및 멤버 정보를 유지하며, 창 관리자에 붙어 있는 상태로 유지), 메모리가 부족한 경우 시스템이 중단시킬 수도 있습니다.

- 정지됨 Stopped: 액티비티가 다른 액티비티에 `완전히` 가려진 상태. 이 때는 액티비티가 완전히 살아 있지만(Activity 객체가 메모리에 보관되어 있고, 모든 상태 및 멤버 정보를 유지하며, 창 관리자에 붙어 있는 상태로 유지), 메모리가 부족한 경우 시스템이 중단시킬 수도 있습니다.

## 액티비티 생명 주기 Lifecycle

액티비티 프로그램의 상태에 따른 생명 주기를 갖는데, 각각의 생명주기마다 호출되는 콜백 메서드가 따로 있습니다.

![](https://developer.android.com/images/activity_lifecycle.png?hl%3Dko)

>출처: 구글 안드로이드 공식 홈페이지

1. `onCreate()`: 액티비티를 생성, 액티비티의 필수 구성 요소를 초기화, `setContentView()`를 호출해서 액티비티에 UI를 정의할 수 있음

2. `onStart()`: 액티비티가 보여지기 시작함

3. `onResume()`: 액티비티가 시작되고 사용자가 상호작용하기 직전에 호출

4. `onPause()`: 액티비티가 부분적으로 가려짐 이라고 했죠? 사용자가 액티비티를 떠난다는 신호. 현재 사용자가 세션을 넘어서 정보가 지속되어야 한다면 변경 사항을 커밋하기에 가장 적절한 콜백(사용자가 돌아오지 않을 수도 있음)

5. `onStop()`: 액티비티가 더 이상 사용자에게 표시되지 않으면 호출

6. `onRestart()`: 액티비티가 중단되었다가 다시 시작되기 전에 호출

7. `onDestroy()`: 액티비티가 소멸되기 직전에 호출됩니다. 액티비티가 받는 마지막 호출

## 액티비티의 수명

- Whole Lifecycle: onCreate() ~ onDestroy(), 액티비티 전체 생명 주기

- Visible Lifecycle: onStart() ~ onStop(), 가시적으로 보이는 액티비티 생명 주기

- Foreground Lifecycle: onResume() ~ onPause(), 포그라운드에 떠있는 생명 주기

## 액티비티 상태 저장

화면이 회전하거나, `onPause()`나 `onStop()` 상태에서 시스템이 메모리를 필요로 하면 강제로 액티비티가 종료되고, 이로 인해 기존에 있던 정보가 날아갈 수 있습니다. 이를 위해 데이터를 저장하여 액티비티가 시작될 때 복원이 되게끔 처리해야 합니다.

아.. 네?

- 화면 회전

    - 화면 회전이 되면,

    - onPause() -> onStop() -> onDestroy()가 호출이 되며

    - 기존 액티비티가 소멸됩니다.

    - 그리고 다시 onCreate() -> onStart() -> onResume()을 호출하여

    - 새로 액티비티를 생성하는데

    - 이 때 기존에 액티비티가 가지고 있던 정보가 사라질 수 있습니다

아~

..근데?

최근에 Android Jetpack으로 나온 `LiveData`는 생명주기에 맞게 옵저버 패턴으로 구현이 되어 있으니까.. 이거 쓰는 게 훨씬 좋답니다!

## 백스택 (= Activity Task)

보통 안드로이드 앱에서는, 단일 액티비티가 아닌.. 여러 액티비티를 이용하여 UI를 구성하게 되는데요

이 때 새로 열리는 액티비티는 각각 백 스택을 통해서 관리가 됩니다.

하지만 Back 키를 눌러서 현재 액티비티를 종료시키면, 종료된 액티비티가 POP이 되면서 그 아래에 있던 액티비티가 푸시가 됩니다.

네?

![](https://miro.medium.com/max/700/1%2ATBrYO4y6HXwPXvtpd7Vh1A.png)

백 스택(=Task)는 동시에 여러 개를 가질 수 있습니다.

## 액티비티의 기본 동작

- 액티비티 A가 액티비티 B를 시작하면

    - 액티비티 A는 중단되지만,

    - 시스템이 그 상태를 (예: 스크롤 위치 및 양식에 입력된 테스트 등) 보존합니다.

    - 사용자가 액티비티 B에 있는 동안 뒤로 버튼을 누르면 액티비티 A가 재개되며 상태도 복원됩니다.

- 사용자가 홈 버튼을 눌러 작업을 떠나면

    - 현재 액티비티가 중단되고 해당 작업이 백그라운드로 들어갑니다.

    - 시스템은 작업에 속한 모든 액티비티의 상태를 보존합니다.

    - 사용자가 나중에 작업을 시작한 시작 관리자 아이콘을 선택하여 해당 작업을 재개하면,

    - 그 작업이 포그라운드로 나오고

    - 스택 맨 위에서 액티비티를 재개합니다.

- 액티비티는 여러 번 인스턴스화 할 수 있으며, 다른 작업에서도 이를 수행할 수 있습니다.

### 안드로이드 화면스택 전체 제거

🔗[안드로이드 화면스택 전체 제거 :: dooooreeee님 velog](https://velog.io/@dooooreeee/%EC%95%88%EB%93%9C%EB%A1%9C%EC%9D%B4%EB%93%9C-%ED%99%94%EB%A9%B4%EC%8A%A4%ED%83%9D-%EC%A0%84%EC%B2%B4-%EC%A0%9C%EA%B1%B0)

![](https://velog.velcdn.com/images%2Fdooooreeee%2Fpost%2Fc50f0dbb-c662-4fc1-9b34-27492c6f8969%2F%E1%84%89%E1%85%B3%E1%84%90%E1%85%A2%E1%86%A8.png)

안드로이드 화면은 스택 형식으로 쌓이게 된다는 거.. 짐작하고 있었지요?

제법 거슬리기도 했었어요 맞아요

저도 프로젝트에서 이.. 스택이라는게 너무 많이 쌓이는 것 같아서 거슬렸어요

Fragment로 구성한 화면은 괜찮았는데.. Activity가 여러 개 이어지는 페이지는 좀 그렇더라구요

```kotlin
Handler().postDelayed(Runnable {
    val intent = Intent(this@StartActivity, LoginActivity::class.java)
    finishAffinity()
    startActivity(intent)
}, 2000)
```

`finishAffinity()`를 사용해 기존 스택을 비움으로써, 거슬림을 해결할 수 있었답니다..
