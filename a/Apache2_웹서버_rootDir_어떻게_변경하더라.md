# Apache2 웹서버 Document root 디렉토리 변경하기

```shell
sudo vi /etc/apache2/apache2.conf
```

```shell
sudo vi /etc/apache2/sites-available/000-default.conf
```

여기는 -> DocumentRoot 경로를 손 대는 거였죠

그러고나서

```shell
sudo service apache2 restart
```

그리고, 바꾼 디렉토리에 접근 가능하도록 설정하는 것도 필요함

```shell
sudo chcon -R -t httpd_user_content-t /asdf/asdf
```
