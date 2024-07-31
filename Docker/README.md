# Docker

## 목차

- [Docker 관련 bash shell 명령어](#docker-관련-bash-shell-명령어)
- [Dockr 명령어 요약](#dockr-명령어-요약)
- [docker run](#docker-run)
- [docker start](#docker-start)
- [TTY(텔레타입)](#tty텔레타입)

# Docker 관련 bash shell 명령어

```shell
sudo service docker status # Docker가 서비스 실행 중인지 확인
sudo service docker start # Docker 서비스를 수동으로 시작
sudo service docker restart
```

# Dockr 명령어 요약

```shell
docker search <이미지 이름> # 이미지 검색
docker images # 이미지 목록 확인
docker ps # 실행 중인 컨테이너 목록 확인
docker ps -a # 모든 컨테이너 목록 확인
docker rm <컨테이너 ID or name> # 컨테이너 삭제

docker stop <컨테이너 ID or name> # 컨테이너 중지
docker start <컨테이너 ID or name>
docker restart <컨테이너 ID or name>
docker pause <컨테이너 ID or name>
docker unpause <컨테이너 ID or name>

docker exec -it <컨테이너 ID or name> bash # 컨테이너의 터미널에 접속
# `-i`: 인터렉티브 모드 활성화(표준 입력을 유지하여 터미널에 입력할 수 있다.)
# `-t`: TTY(텔레타입) 모드 활성화(터미널의 tty를 할당하여 터미널로 사용할 수 있다.)
# `/bin/bash`: 터미널 접속에 bash 쉘 사용
```

# docker run

- `docker run` 명령어는 Docker 컨테이너를 생성하고 시작하는 데 사용됩니다. 이 명령어는 Docker 이미지에서 컨테이너를 처음부터 시작할 때 사용됩니다. 필요한 경우, Docker Hub에서 이미지를 다운로드 하는 것부터 시작해, 지정된 이미지에서 새로운 컨테이너를 생성하고, 시작합니다. 포트 매핑, 환경 변수, 볼륨 마운트 등 다양한 옵션을 적용할 수 있습니다.

```bash
docker run -d --name aivle -v $(pwd):/app -p 8000:8000 django:latest
```

- `docker run`: 새로운 Docker 컨테이너를 생성하고 실행하는 명령어입니다.
- `-d`: 컨테이너를 데몬 모드로 실행합니다. 이 옵션을 사용하면 컨테이너가 백그라운드에서 실행되며, 터미널을 점유하지 않습니다.
- `--name aivle`: 생성되는 컨테이너의 이름을 `aivle`로 지정합니다. 이름을 지정하면 <컨테이너 ID> 대신 이름으로 컨테이너를 참조할 수 있습니다.
- ⭐ `-v $(pwd):/app`: 볼륨 마운트 옵션입니다. 호스트의 현재 작업 디텍토리(`$(pwd)`)를 컨테이너의 `/app` 디렉토리에 마운트합니다.
- `-p 8000:8000`: 포트 포워딩 옵션입니다. 호스트의 포트 8000을 컨테이너의 포트 8000에 매핑합니다. 이 옵션을 사용하면 호스트의 `http://localhost:8000`에 접속 시 컨테이너 내부에서 실행 중인 웹 서버에 접근할 수 있는 것입니다.
- `django:latest`: 사용할 Docker 이미지 이름과 태그를 지정합니다. 여기서는 `django` 이미지를 사용하며, `latest` 태그는 최신 버전을 의미합니다.

>의문: `docker run`에서도 `-it` 옵션을 붙여 사용하기도 하나요?

- 그렇다고 합니다. 다음과 같은 예시를 보면,

```bash
docker run -it --name my-container ubuntu /bin/bash
```

- 위 명령어는 `ubuntu` 이미지를 기반으로 `my-container`라는 이름의 컨테이너를 생성하고, 컨테이너 내부에서 `/bin/bash` 셸을 실행합니다. 이 경우 `-it` 옵션 덕분에 사용자는 **터미널을 통해 컨테이너와 상호작용할 수 있습니다**.
- 때로는 `-d`(detached) 옵션과 `-it` 옵션을 함께 사용하고 싶다는 생각이 들 수도 있는데, 이 옵션은 **상호 베타적인 경우가 많습니다**. `-d`는 컨테이너를 백그라운드에서 실행하는 데 사용되고, `-it`는 터미널 인터페이스를 활성화하는 데 사용되므로 동시에 사용할 실질적인 이유는 없습니다.
- 다만, 특정 상황에서는 컨테이너를 백그라운드에서 실행한 후, 나중에 `docker exec -it` 명령어를 사용하여 터미널에 접속할 수 있습니다.

# docker start

- `docker start` 명령어는 이미 생성되어 있던 (하지만 중단된) 컨테이너를 다시 시작하는 데 사용됩니다. 이 명령어는 새로운 컨테이너를 생성하지는 않으며, 기존의 컨테이너를 다시 실행합니다. 주로 `docker run`으로 생성했던 컨테이너를 중지한 후 다시 시작할 때 사용합니다.

# TTY(텔레타입)
- '텔레타입'은 "컴퓨터와 사용자 간 상호작용을 가능하게 한 초기 장치"를 의미합니다. (터미널 인터페이스의 초기 형태)
- 현대적 의미로는, "소프트웨어적으로 구현된 가상 터미널"을 의미합니다.
- 즉, "가상 터미널을 활성화하여 사용자와 컨테이너 간 상호작용을 가능하게 한다"고 이해하면 되겠습니다.