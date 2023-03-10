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
