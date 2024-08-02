# Apache2

## 목차

- [Apache2 웹서버 Document root 디렉토리 변경하기](#apache2-웹서버-document-root-디렉토리-변경하기)
- [가상 호스트 설정해서 여러 프로젝트 운영하기](#가상-호스트-설정해서-여러-프로젝트-운영하기)

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

# 가상 호스트 설정해서 여러 프로젝트 운영하기

1. 새로운 디렉토리 생성
```bash
sudo mkdir -p /path/to/your/new/project1
sudo mkdir -p /path/to/your/new/project2
sudo chown -R $USER:$USER /path/to/your/new/project1
sudo chown -R $USER:$USER /path/to/your/new/project2
sudo chmod -R 755 /path/to/your/new/project1
sudo chmod -R 755 /path/to/your/new/project2
```

- `chown` 명령: 파일이나 디렉토리의 소유자와 그룹을 변경합니다.
    - `sudo chown -R $USER:$USER /path/to/your/new/project1`
        - `-R`: 재귀적으로 하위 디렉토리와 파일들까지 모두 변경합니다.
        - `$USER:$USER`: 현재 사용자와 현재 사용자의 기본 그룹으로 소유자와 그룹을 변경합니다.
        - `/path/to/your/new/project1`, `/path/to/your/new/project2`: 소유자와 그룹을 변경할 디렉토리 경로입니다.
- `chmod` 명령: 파일이나 디렉토리의 권한을 설정합니다.
    - `sudo chmod -R 755 /path/to/your/new/project1`
        - `-R`: 재귀적으로 하위 디렉토리와 파일들까지 모두 변경합니다.
        - `755`: 파일 권한을 설정하는 숫자입니다.
            - `7`: 사용자/소유자(Owner)에게 읽기(r), 쓰기(w), 실행(x) 권한을 부여합니다.
            - `5`: 그룹(Group)에게 읽기(r), 실행(x) 권한을 뷰여합니다.
            - `5`: 다른 사용자(Ohter)에게 읽기(r), 실행(x) 권한을 뷰여합니다.
            - 즉, 권한을 비트의 합으로 나타내는 것입니다. `r = 4`, `w = 2`, `x = 1`로 표현되며, 이 비트들을 더해서 특정 권한을 나타내는 숫자로 만듭니다.
        - `/path/to/your/new/project1`, `/path/to/your/new/project2`: 권한을 변경할 디렉토리 경로입니다.

2. 가상 호스트 설정 파일 작성
    - 각 프로젝트에 대한 가상 호스트 설정 파일을 작성합니다.

`/etc/apache2/sites-available/project1.conf`:
```bash
<VirtualHost *:80>
    ServerAdmin webmaster@project1.com
    DocumentRoot /path/to/your/new/project1
    ServerName project1.com
    <Directory /path/to/your/new/project1>
        Options Indexes FollowSymLinks
        AllowOverride All
        Require all granted
    </Directory>
    ErrorLog ${APACHE_LOG_DIR}/project1_error.log
    CustomLog ${APACHE_LOG_DIR}/project1_access.log combined
</VirtualHost>
```

`/etc/apache2/sites-available/project2.conf`:
```bash
<VirtualHost *:80>
    ServerAdmin webmaster@project1.com
    DocumentRoot /path/to/your/new/project1
    ServerName project1.com
    <Directory /path/to/your/new/project1>
        Options Indexes FollowSymLinks
        AllowOverride All
        Require all granted
    </Directory>
    ErrorLog ${APACHE_LOG_DIR}/project1_error.log
    CustomLog ${APACHE_LOG_DIR}/project1_access.log combined
</VirtualHost>
```

3. 가상 호스트 설정 활성화

```bash
sudo a2ensite project1.conf
sudo a2ensite project2.conf
sudo service apache2 reload
```

이렇게 하면, 각 프로젝트는 `/path/to/your/project1` 및 `/path/to/your/project2` 디렉토리를 DocumentRoot로 사용하게 됩니다. 이 방법으로 여러 프로젝트를 효율적으로 관리할 수 있습니다.

- `a2ensite`: Apache2 웹 서버에서 특정 사이트 설정 파일을 활성화(enable)하는 데 사용되는 명령어입니다. 이 명령어를 사용하면 쉽게 가상 호스트 설정을 활성화할 수 있습니다.
- Apahce2는 여러 웹사이트를 하나의 서버에서 호스팅할 수 있는 기능을 제공합니다. 이를 가상 호스트(Virtual Host)라고 합니다. 각 가상 호스트는 별도의 설정 파일로 관리되며, 이 설정 파일을 통해 특정 도메인이나 IP 주소에 대한 웹사이트 구성을 정의할 수 있습니다.
- `a2ensite` 명령어는 `/etc/apache2/sites-available/` 디렉토리에 있는 사이트 설정 파일을 `/etc/apache2/sites-enabled/` 디렉토리에 심볼릭 링크로 추가하여 활성화합니다. Apache2는 이 심볼릭 링크를 통해 어떤 사이트 설정 파일을 활성화할 지 결정합니다.
- 반대로, 특정 사이트 설정 파일을 비활성화하려면 `a2dissite` 명령어를 사용합니다. `/etc/apache2/sites-enabled/` 디렉토리에서 지정된 설정 파일의 심볼릭 링크를 제거하여 해당 가상 호스트 설정을 비활성화합니다.