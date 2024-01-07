https://velog.io/@charbs0701/WSL2-mongo-%EC%84%A4%EC%B9%98-%EC%82%AC%EC%9A%A9
이거 참고함

Mongo 인스턴스 실행:

```shell
sudo mongod --dbpath ~/data/db/
```

인스턴스가 잘 실행되고 있는지 확인하려면 어떻게 하나요?

```shell
ps -e | grep 'mongod'
```

인스턴스가 잘 실행되고 있을 때

다른 터미널 창에 `mongo` 입력하면 mongodb shell을 사용할 수 있답니다

```shell
mongo
```

