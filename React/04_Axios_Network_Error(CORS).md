# Axios Network Error

동아리 웹 홈페이지 프로젝트 진행 중

회원가입 시 아이디의 중복 여부 체크를 하는 API가 작동은 되는데

React 쪽에서 axios를 통해 호출했을 시

Network Error가 발생하는 문제..

찾아보니, The error is often caused by CORS issues 라고 한다..

🔗[Axios Network Error when making HTTP request [Solved] :: bobbyhadz.com](https://bobbyhadz.com/blog/react-axios-network-error-stack-trace)

>CORS는 서버가 HTTP 헤더의 조합을 사용하여 요청을 수신하는 도메인을 표시할 수 있는 메커니즘 입니다.

읽어보니..

- 당신의 서버는 응답에 필요한 CORS 헤더를 전송해야 합니다

라는데요?

```shell
$ npm install cors
```

```js
const express = require('express');
const cors = require('cors');

const app = express();

// 👇️ configure CORS
app.use(cors());

app.get('/products/:id', function (req, res, next) {
  res.json({msg: 'This is CORS-enabled for all origins!'});
});

const PORT = 3456;

app.listen(PORT, function () {
  console.log(`CORS-enabled web server listening on port ${PORT}`);
});
```

```cors
# 👇️ your domain below, e.g. http://localhost:3000
Access-Control-Allow-Origin: http://example.com

Access-Control-Allow-Methods: POST, PUT, PATCH, GET, DELETE, OPTIONS

Access-Control-Allow-Headers: Origin, X-Api-Key, X-Requested-With, Content-Type, Accept, Authorization

# 👇️ only if your browser sends user credentials (cookies or Auth headers)
Access-Control-Allow-Credentials: true

```

흠..

그래서 저 cors를 어떻게 설정하냐는 건데

찾다보니 이것은 백엔드 측에서 설정해주는 것도 있고

프런트쪽에서도 시도해 볼 수 있는게 있었다..

🔗[CORS란? CORS를 해결해보자 :: 구보현 블로그](https://bohyeon-n.github.io/deploy/web/cors.html)

🔗[Same-Origin Policy 동일 출처 정책과 CORS 에러 :: yejinh님 velog](https://velog.io/@yejinh/CORS-4tk536f0db)

클라이언트 단에서 시도할 수 있는 해결책을 시도해 보겠다!!

## proxy 설정

- 다양한 이유로 (주로 보안의 문제로) 직접 통신하지 못하는 두 개의 컴퓨터 사이에서 서로 통신할 수 있도록 돕는 역할을 가리켜 프록시라 일컫는다.

🔗[[React]CORS 에러 해결](https://developer-talk.tistory.com/91)

`FrontEnd - package.json`
```json
{
  ...,
  "proxy": "http://localhost:3001",
  ...
}
```

`"proxy": 접근할 도메인`

이렇게 해주고

`FrontEnd 요청 단`
```js
fetch('/test')
  .then((response) => {
    if(response.ok) {
      return response.json();
    }  
    throw new Error('Network response was not ok.');
  }).then((data) => {
    console.log(JSON.stringify(data));
  }).catch((error) => {
    console.log(`error: ${error}`)
});
```

이런식으로, End-Point만 작성해 줬더니..

CORS 에러는 일단 해결된 것 같다..! 🥹
