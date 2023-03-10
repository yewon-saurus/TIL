# 읽기

```py
@app.route('/read/<int:id>/')
# 패턴 차원에서, int로 type을 지정
def read(id):
    liTags = ''
    for topic in topics:
        liTags = liTags + f'<li><a href="/read/{topic["id"]}/">{topic["title"]}</a></li>'
    title = ''
    body = ''
    for topic in topics:
        if id == topic['id']:
            title = topic['title']
            body = topic['body']
            break
    return f'''<!doctype html>
    <html>
        <body>
            <h1><a href="/">WEB</a></h1>
            <ol>
                {liTags}
            </ol>
            <h2>{title}</h2>
            {body}
        </body>
    </html>
    '''
```

중복되는 부분이 너무 많아서,

템플릿 도 써볼게요

```py
def template(contents, content):
    return f'''
    <!doctype html>
    <html>
        <body>
            <h1><a href="/">WEB</a></h1>
            <ol>
                {contents}
            </ol>
            {content}
        </body>
    </html>
    '''

def getContents():
    liTags = ''
    for topic in topics:
        liTags = liTags + f'<li><a href="/read/{topic["id"]}/">{topic["title"]}</a></li>'
        # f String이 쓰였어요
        # 문자열을 변수와 같이 섞을 때 쓰면 편리!
    return liTags
```

오~

코드를 재사용 했네요..

깔끔해졌어요..

# 쓰기

`<input>` 태그에서 name 속성

- input 태그에 값을 입력 했을 때, 서버에 전송될 때 이름이 필요한데요.. -> 걔가 name 속성 이에요 -> 서버에 어떤 이름으로 전송할 것인가

어디로 전송할 것인지도 알려줘야 하는데요..

- 그걸 지정할 때 `<form>` 태그를 써요

- 사용자가 입력한 정보를 서버로 전송하는 역할을 하는 것!!

- action 속성은, 서버에 어떤 경로로 전송할 것인가.. 라는 것입니다

```py
@app.route('/create/')
def create():
    content = '''
        <form action="/create/">
            <p><input type="text" name="title" placeholder="title"></p>
            <p><textarea name="body" placeholder="body"></textarea></p>
            <p><input type="submit" value="create"></p>
        </form>
    '''
    return template(getContents(), content)
```

이렇게 했어요

action에도 그냥 /create/ 넣어줬어요(굳이 다르게 할 이유 없어서)

이렇게 전송한 형태의 데이터는, URL에 데이터가 포함돼 있거든요

URL을 통해 서버로 데이터를 보내는 방식 -> **GET 방식**

서버로 데이터를 전송할 때, URL에 데이터가 포함돼 있다.. (어쨌든 같은 말이죠?)

```
웹 서비스에서, 특정한 페이지를 식별하는 고유한 주소로써 사용되는 것 -> GET 방식
```

값을 변경할 때는 POST 방식 을 쓰는데요..

```py
@app.route('/create/')
def create():
    content = '''
        <form action="/create/" method="POST">
            <p><input type="text" name="title" placeholder="title"></p>
            <p><textarea name="body" placeholder="body"></textarea></p>
            <p><input type="submit" value="create"></p>
        </form>
    '''
    return template(getContents(), content)
```

form 태그의 method는 기본값이 GET이에요(생략하면 GET)

지금은 POST로 해줬죠

얘는 URL 안에 데이터가 포함되어 있지 않아요

해당 URL에 접근할 때마다 서버에 데이터가 쌓이면.. 난감해 질수도 있죠?

값을 감추는 방식 -> **POST 방식**

이렇게 웹 브라우저가 서버한테 전송한 데이터는, URL이 아닌, payload 라는 것 안에, 감춰진 상태로 -> 은밀하게 전송 -> URL에 드러나지 않아요

그리고 POST 방식으로 하면.. -> 훨씬 더 큰 데이터를 안전하게 전송할 수 있기 때문에.. NICE ^^

가져올 때 -> GET

데이터 변경 필요하니? -> POST

---

GET, POST 는 HTTP Methods 중 하나 입니다..

그리고 얘네를 쓰려면

이 route가 허용하는 methods를 지정해야 합니다?

```py
@app.route('/create/', methods=['GET', 'POST'])
def create():
    content = '''
        <form action="/create/" method="POST">
            <p><input type="text" name="title" placeholder="title"></p>
            <p><textarea name="body" placeholder="body"></textarea></p>
            <p><input type="submit" value="create"></p>
        </form>
    '''
    return template(getContents(), content)
```

아 근데

`request.method`라는게 있는데요

flask는 이걸 보고 -> 얘가 GET 인지 POST 인지 알아내요

---

지금 create 기능 구현하고 있는데요

글을 작성 완료하고 create submit을 하고 나면, 페이지가 어디로 이동해야 할까나요?

해당 페이지로 이동하게 하는 게 자연스럽겠죠?

이걸 `redirection`을 사용해서 할 수 있어요

- 웹 브라우저한테, 어디로 이동 하시오~ 하고 명령을 내리는 것입니다..

- import 하셔야 해요

