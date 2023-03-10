# 수정

topic을 클릭해서 -> read로 들어갔을 때

수정 기능이 나타나면 좋겠네요

그리고 수정 버튼을 눌렀을 때 -> /update/<topicId> 이렇게 나오면 좋겠어요

흠.. 그렇다면 해당 topic의 id값이 공급되는 게 필요하겠구나

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

각 페이지에 들어가면 update가 보이게 된답니다..

---

근데 업데이트 라는건 있잖아요

업데이트 딱 하러 왔을 때

기존 내용들이 싹 같이 불려와야 수정할 때도 편하겠죠?(비어있으면 난감..)

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

이런 식으로 처리를 해줘야겠죠..

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
