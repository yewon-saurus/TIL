# Flask

>파이썬 웹 프레임 워크의 양대 산맥인 플라스크!
Django 대비 이해하기 쉬운 사용방법으로 인해서
많은 사람들의 사랑을 받고 있는 웹 프레임 워크 입니다..

- 웹 프레임 워크는 웹페이지를 찍어내는 공장입니다.
- routing은 사용자의 요청을 처리 할 응답 함수를 연결하는 작업입니다.
- form 태그는 서버로 데이터를 전송하는 UI를 만듭니다.
- GET은 정보를 가져올 때 POST는 정보를 변경할 때 사용합니다.
- Create, Read, Update, Delete는 정보기술의 바탕이 되는 작업들입니다.
- 리다이렉션은 웹브라우저를 강제로 다른 페이지로 이동하는 수단입니다.

## 목차

- [Routing](#routing)
- [Read](#read)
- [Create](#create)
- [Update](#update)
- [Delete](#delete)

# Routing

본문에 들어가기에 앞서 잠깐!

```shell
$ pip install flask
```

flask 설치는 이렇게 하면 되구요

```
$ python server.py
```

실행은 이렇게 하면 됐어요~

여기서 server.py는 파일명이죠?

![실행해 본 모습](./img/01_01.png)

여기서 `http://127.0.0.1:5000` ctrl + 클릭 해서 이동하면 돼요

# Routing

웹 프레임워크를 처음 배울 때, 이 웹 프레임워크는 라우팅을 어떻게 하는지 부터 알아두는 게 좋습니다. 라우팅을 할 줄 알면 Flask의 반을 한 것입니다.

```py
@app.route('/')
def index():
    return 'Index Page'

@app.route('/hello')
def hello():
    return 'Hello, World'
```

```py
@app.route('/read/1/')
def read():
    return 'read 1'
```

저기 `1` 부분을 변수로 관리하고 싶으면 아래처럼 할 수 있습니다.

```py
@app.route('/read/<id>/')
def read(id):
    print(id)
    return 'read ' + id
```

# Read

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

아래 코드는, 위에서 중복되는 부분이 너무 많아서, 템플릿을 사용한 모습입니다.

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

# Create

`<input>` 태그에서 name 속성

- input 태그에 값을 입력 했을 때, 서버에 전송될 때 이름이 필요한데 -> 걔가 name 속성 이에요 -> "서버에 어떤 이름으로 전송할 것인가"

어디로 전송할 것인지도 알려줘야 합니다.
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

action에도 그냥 /create/ 넣어줬어요(굳이 다르게 할 이유 없어서)
- 이렇게 전송한 형태의 데이터는, URL에 데이터가 포함돼 있거든요
- URL을 통해 서버로 데이터를 보내는 방식 -> **GET 방식**
- 서버로 데이터를 전송할 때, URL에 데이터가 포함돼 있다.. (어쨌든 같은 말이죠?)

```
웹 서비스에서, 특정한 페이지를 식별하는 고유한 주소로써 사용되는 것 -> GET 방식
```

값을 변경할 때는 POST 방식을 씁니다.

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

form 태그의 method는 기본값이 GET이에요(생략하면 GET)(지금은 POST로 해줬죠)
- 얘는 URL 안에 데이터가 포함되어 있지 않아요
- 해당 URL에 접근할 때마다 서버에 데이터가 쌓이면.. 난감해 질수도 있죠?
- 값을 감추는 방식 -> **POST 방식**
- 이렇게 웹 브라우저가 서버한테 전송한 데이터는, URL이 아닌, payload 라는 것 안에, 감춰진 상태로 -> 은밀하게 전송 -> URL에 드러나지 않아요
- 그리고 POST 방식으로 하면.. -> 훨씬 더 큰 데이터를 안전하게 전송할 수 있기 때문에.. NICE ^^

즉, 어떻게 쓰는 걸 추천하는 것이냐
- 가져올 때 -> GET
- 데이터 변경 필요하니? -> POST

GET, POST 는 HTTP Methods 중 하나 입니다.
- 그리고 얘네를 쓰려면, 이 route가 허용하는 methods를 지정해야 합니다?

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

`request.method`라는게 있는데, flask는 이걸 보고 -> 얘가 GET 인지 POST 인지 알아냅니다.

웹 브라우저한테, 어디로 이동 하시오~ 하고 명령을 내리는 것 `redirection`

# Update

- "topic을 클릭해서 -> read로 들어갔을 때, 수정 기능이 나타나면 좋겠다"
- "그리고 수정 버튼을 눌렀을 때 -> /update/<topicId> 이렇게 나오면 좋겠다"

그렇다면 해당 topic의 id값이 공급되는 게 필요하겠습니다.

```py
def template(contents, content, id=None):
    # id가 필요하지 않은 페이지도 있거든요.. id의 기본값을 None으로 정함
    # ex) Welcome page

    contextUI = ''
    if id != None:
        contextUI = '''
        <li><a href="/update/{id}/">update</li>
        '''
    # 이하 생략
```

근데 업데이트 라는건, 업데이트 딱 하러 왔을 때, 기존 내용들이 싹 같이 불려와야 수정할 때도 편하겠죠?(비어있으면 난감해요)

```py
def update(id):
    if request.method == 'GET': 
        title = ''
        body = ''
        for topic in topics:
            if id == topic['id']:
                title = topic['title']
                body = topic['body']
                break
        content = f'''
            <form action="/update/{id}/" method="POST">
                <p><input type="text" name="title" placeholder="title" value="{title}"></p>
                <p><textarea name="body" placeholder="body">{body}</textarea></p>
                <p><input type="submit" value="update"></p>
            </form>
        '''
        # 이하 생략
```

이런 식으로 처리를 해주면 굿

```py
@app.route('/read/<int:id>/')
# 패턴 차원에서, int로 type을 지정
def read(id):
    title = ''
    body = ''
    for topic in topics:
        if id == topic['id']:
            title = topic['title']
            body = topic['body']
            break
    return template(getContents(), f'<h2>{title}</h2>{body}', id)
```

read 페이지에서도 template를 return 할 때, id를 넘겨주도록 수정 해줬어요

# Delete

근데 update 할 때는 a 태그를 이용해서 -> 링크를 써서 했습니다만..

삭제 기능은 복잡하지 않게, 그냥 클릭하면 사라지게 하겠습니다.

```jsx
왜죠?
```

- 삭제하는 기능의 링크를 입력해버렸어요

- 사용자가 원하지 않았는데도, 삭제가 되어 버리는 현상 발생!!(POST 처음 설명할 때 말씀해주셨던 이유와 매우 유사하죠?)

```py
@app.route('/delete/<int:id>/', methods=['POST'])
# POST만 허용하겠습니다..
def upddeleteate(id):
    for topic in topics:
        if id == topic['id']:
            topic.remove(topic)
            break
    return redirect('/')
```
