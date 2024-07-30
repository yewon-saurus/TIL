# Docker

## 목차

- [Docker 관련 bash shell 명령어](#docker-관련-bash-shell-명령어)
- [Dockr 명령어 요약](#dockr-명령어-요약)
- [docker run](#docker-run)
- [docker start](#docker-start)

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

docker exec -it <컨테이너 ID or name> /bin/bash # 컨테이너의 터미널에 접속
# `-i`: 인터렉티브 모드 활성화(표준 입력을 유지하여 터미널에 입력할 수 있다.)
# `-t`: TTY(텔레타입) 모드 활성화(터미널의 tty를 할당하여 터미널로 사용할 수 있다.)
# `/bin/bash`: 터미널 접속에 bash 쉘 사용
```

# docker run

- `docker run` 명령어는 Docker 컨테이너를 생성하고 시작하는 데 사용됩니다. 이 명령어는 Docker 이미지에서 컨테이너를 처음부터 시작할 때 사용됩니다. 필요한 경우, Docker Hub에서 이미지를 다운로드 하는 것부터 시작해, 지정된 이미지에서 새로운 컨테이너를 생성하고, 시작합니다. 포트 매핑, 환경 변수, 볼륨 마운트 등 다양한 옵션을 적용할 수 있습니다.

```shell
docker run -d -p 80:80 nginx
# `-d`: 컨테이너를 데몬 모드로 실행(옵션 없을 시, 포그라운드에서 실행되어 터미널을 점유하게 됨)
# `-p 80:80`: 호스트와 컨테이너 간 포트 매핑 설정.. 호스트 머신의 포트 80으로 들어오는 요청은 컨테이너 포트의 80으로 전달됨
    # 첫 번째 `80`: 호스트 머신의 포트 번호
    # 두 번째 `80`: 컨테이너 내부의 포트 번호
```

# docker start

- `docker start` 명령어는 이미 생성되어 있던 (하지만 중단된) 컨테이너를 다시 시작하는 데 사용됩니다. 이 명령어는 새로운 컨테이너를 생성하지는 않으며, 기존의 컨테이너를 다시 실행합니다. 주로 `docker run`으로 생성했던 컨테이너를 중지한 후 다시 시작할 때 사용합니다.