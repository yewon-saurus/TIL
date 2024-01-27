# change image path C to D

https://mungkhs1.tistory.com/18

- 다음을 진행하기 전에, docker를 완전히 종료(Stopped)시켜주는 것 잊지 말기

그리고 이제 power shell에서

```shell
wsl --export docker-desktop-data "D:\Docker\docker-data.tar"
```

```shell
wsl --unregister docker-desktop-data
```

```shell
wsl --import docker-desktop-data "D:\Docker" "D:\Docker\docker-data.tar" --version 2
```

까지 하고, `D:\Docker`에 `ext4.vhdx`가 생성된 것까지 확인되면

처음에 생성한 `D:\Docker\docker-data.tar`는 삭제해도 된다.

