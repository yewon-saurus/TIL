# Docker 메모

에이블스쿨 빅프로젝트 진행 중, docker를 써서 프로젝트를 관리해보고 싶어 이렇게 작성해 봅니다.

docker desktop을 통해 django:latest Image를 다운 받았고,


프로젝트 폴더에서

```bash
docker run -d --name aivle -v $(pwd):/app -p 8000:8000 -t django:latest bash
```

했습니다.

- `-v $(pwd):/app`: 현재 디렉토리를 컨테이너 내의 `/app` 디렉토리로 마운트

- `-p 8000:8000`: 호스트의 8000번 포트와 컨테이너의 8000번 포트를 매핑

- `-it`: 대화형 모드로 실행하라는 뜻

- `django:latest`: 사용할 이미지의 이름/태그

- `bash`: 컨테이너 내에서 bash 쉘을 실행하라는 뜻

그러고 나서

```bash
docker exec -t aivle bash
```

하니까, 컨테이너에 접속이 가능했습니다.

