# CI? CD? ㅠㅠ

어렴풋이 느낌적인 느낌만 짚고 있던 CI CD가 뭔지 진짜 이제는 정말로 명확히 알아두는 게 좋지 않을까? 적당적당히 공부하고 스르륵 회피하는 ~~공부법~~ 짓은 이제 그만두자..

CI/CD

DevOps 엔지니어의 핵심 업무

- CI: Continuous Integration

지속적인 통합이 뭐죠

```
app의 새로운 변경 사항(코드 등)이
정기적으로 빌드 & 테스트되어
공유 레포지토리에 통합되는 것을 의미
```

```
다수의 개발자가 형상관리 툴을 공유하여 사용하는 환경
(Git, SVN 등)

기능 추가 시 -> 버전 업데이트
다수의 개발자 -> 수많은 commit

아아.. 기능마다 빌드/테스트/병함 하기가 너무 번거롭다

~ 이 런 상 황 에 서 ~
자동화된 빌드&테스트가 되면
얼마나 좋을까..
-> 원천 소스코드의 충돌도 방지 될테고..
```

- CI의 핵심 목표
    - 버그를 신속히 찾아 해결
    - sw의 품질 개선
    - 새로운 업데이트의 검증 및 릴리즈 시간 단축

- CD: Continuous Delivery & Continuous Deployment

>네.. 일단 Delivery랑 Deployment가 다르다는 점 이해를 해볼게요

>지속적인 서비스 제공? 지속적인 배포?

- Continuous Delivery: 공유 레포지토리로 자동으로 release 하는 것
- Continuous Deployment: Production 레벨까지 자동으로 deploy 하는 것

네?

그러니까 뭐냐면..

```
CI -> 새로운 소스코드의 빌드, 테스트, 병합까지
CD -> 개발자의 변경사항이 레포지토리를 넘어 -> 고객의 Production 환경까지 release
```

아.. 넵

아!

```
DevOps 엔지니어가..
CI/CD를 위한 파이프라인을 구성 -> 자동화
하더라는 것이죠?
```

- Jenkins
- Travis CI
- Bamboo
- ⭐ GitHub Actions

# 참고

[데이터 기반으로 지속적인 CI/CD 개선 환경 만들기 :: LINE Engineering](https://engineering.linecorp.com/ko/blog/build-a-continuous-cicd-environment-based-on-data)
