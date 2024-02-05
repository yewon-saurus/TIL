# 안드로이드 SharedPreferences

🔗[안드로이드 자동 로그인 SharedPreferences :: 초보보 혜진님 tistory](https://hyejin.tistory.com/m/26)

안드로이드 자동 로그인을 알아둬야 할 것 같아요(졸.프에 쓸거니까요)

## SharedPreferences 사용하는 이유

개발을 하다 보면

자동 로그인 이라든지..

앱의 데이터들을 관리해야 하는 상황이 있죠

데이터의 양이 많다면.. db에 저장을 하면 되지만, 간단한 데이터들을 db에 넣기 애매한 상황들이 있다..

ShaerdPreferences는 데이터를 파일로 저장한다고 한다..

그래서 파일의 앱 폴더 내에 저장되기 때문에 앱이 삭제되면 데이터도 당연히 삭제 된답니다

(약간 웹에서의 localStorage 같은 걸까요?)

```java
SharedPreferences sharedPreferences = getSharedPreferences("name", Activity.MODE_PRIVATE);
```

- getSharedPreferences() 메서드를 통해서 SharedPreferences 객체를 받아올 수 있다.

    - `name`은 `SharedPreferences의 이름`으로 특정 이름으로 생성할 수 있고, 해당 이름으로 xml 파일이 생성된다고 생각하면 된다.

    - `mode`는 읽고 쓰기 권한 관련된 것으로, `MODE_PRIVATE`는 생성한 application에서만 사용 가능한 것이라고 한다.

```java
loginId = sharedPreferences.getString("inputId", null);
loginPw = sharedPreferences.getString("inputPw", null);
```

SharedPreferences 객체를 통해 원하는 값의 key의 디폴트 값을 파라미터로 하여 호출하면 간단하게 값을 받아 올 수 있다.
