# 안드로이드 화면스택

## 안드로이드 화면스택 전체 제거

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
