# 삭제

이것도 update 버튼 처럼

read 페이지에 있으면 되겠죠?

근데 update 할 때는 a 태그를 이용해서 -> 링크를 써서 했는데요

삭제 기능은 복잡하지 않게, 그냥 클릭하면 사라지게 하겠습니다..

왜냐?

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
