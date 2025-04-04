# Linux

## 목차

- [(WSL/Ubuntu) `hostname -I`를 확인해 보면 IP 주소가 여러 개 나오는데, 왜 여러 개가 나오는 걸까?](#wslubuntu-hostname--i를-확인해-보면-ip-주소가-여러-개-나오는데-왜-여러-개가-나오는-걸까)
- [Symbolic Link](#symbolic-link)

# (WSL/Ubuntu) `hostname -I`를 확인해 보면 IP 주소가 여러 개 나오는데, 왜 여러 개가 나오는 걸까?

- `hostname -I` 명령어를 실행했을 때 두 개의 IP 주소가 나오는 것은 WSL에서 여러 네트워크 인터페이스가 존재하기 때문입니다. 각 IP 주소는 다른 네트워크 인터페이스에 할당된 주소를 나타낼 수 있습니다. WSL에서는 'WSL의 내부 IP 주소(즉, 가상 네트워크 인터페이스의 IP)', 'WSL과 호스트 간의 연결을 위한 IP 주소(localhost, 127.0.0.1)'가 나올 수 있습니다.
- WSL 내부 IP(ex: 172.x.x.x)는 WSL 가상 네트워크의 IP 주소입니다. WSL의 가상 네트워크에서 사용되며, WSL 내의 다른 프로세스 또는 컨테이너와 통신할 때 사용합니다. 이 주소를 사용하여 WSL 내에서 실행 중인 웹 서버에 접속할 수 있습니다. (아~)
- 호스트와의 연결 IP(ex: 192.168.x.x 또는 10.x.x.x)는 말 그대로, WSL와 Windows 호스트 간 네트워크를 연결하는 가상 네트워크 IP 주소입니다. Windows 호스트에서 WSL의 웹 서버에 접근할 때 사용됩니다. 이 IP 주소는 WSL의 네트워크 환경에 따라 다를 수 있습니다.
- `ip a` 명령어를 사용하여 네트워크 인터페이스와의 IP 주소를 자세히 확인할 수 있습니다.

# Symbolic Link

- Docker를 사용하지 않고, Linux에서 일반적인 파일 시스템을 마운트하는 방법을 고민고민하고 조사하였습니다. 조사 결과, Linux에서는 `mount`라는 명령어를 사용해 작업을 수행할 수 있지만, symbolic link는 사용해 비슷한 작업을 해보도록 하겠습니다. symbolic link를 사용하여 호스트 디렉토리의 파일을 WSL의 디렉토리에 연결하는 등 사용할 수 있습니다.
- `sudo ln -s /mnt/c/Users/username/blalla/* /var/www/html`
- `sudo rm 심볼릭링크삭제대상`: 심볼릭 링크를 삭제해도 원본 파일이나 디렉토리는 삭제되지 않습니다.