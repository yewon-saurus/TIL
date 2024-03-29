```
weights, bias, hyper parameter
```

# 심층 신경망

- 심층 신경망의 구조

    - 히든 층이 2개 이상임 ㅋㅋ

    - Multi-layer perceptron

- 심층 신경망의 원리?

    - 계층적 특징을 분석하여 최종 결정

# 딥러닝

- 심층 신경망을 사용하는 기계학습 분야

    - 신경망 자체

        - Multi-Layer Perceptron

            - DBN

            - CNN

            - RNN
        - 2-Layer Perceptron ~ Regression

            - Linear

            - Logistic

            - Softmax
    - Reinforcement Learning

        - GAN
    
    - Supervised Learning vs Unsupervised Learning

    - Discriminative Model vs Generative Model

# 딥러닝의 원리

- 신경망이, 학습을 통해 특징을 자동으로 추출해줌

# 딥러닝 프레임워크

## 일반 신경망과 딥러닝 신경망

- 일반 신경망

    - 원시 데이터 original data 에서 직접 특징 handcrafted feature 을 추출해서 특징 벡터를 입력으로 사용

    - 특징 벡터들의 품질에 영향

    - 사람 손을 많이 타겠네요

- 딥러닝 신경망

    - 특징 추출과 학습을 함께! 동시에! 수행

    - 데이터로부터 효과적인 특징을 학습을 통해 추출 -> `우수한 성능`

# 딥러닝

- deep learning

- 심층학습, 깊은 학습, 심화학습

- 일반 신경망은 소수의 은닉층을 포함하는 데 비해,

- 딥러닝 신경망은 심층 신경망.. -> 다수의 은닉층을 포함하고 있답니다 ^^

# 딥러닝 원동력

- Graphics Processing Unit

- CPU보다 빠르게! 병렬 계산 가능

- 빅데이터 분석 능력 및 처리 속도

    - 디지털 공간 전체가 보다 스마트하게 다룰 수 있는 환경 조성

- 기계를 학습할 수 있는 알고리즘의 진화

- 개발 환경의 진화

    - CLOUD SERVICE + MACHINE LEARNING / DEPP LEARNING

# 활성화 함수

- 활성화는 뉴런을 활성화 할 필요가 있는지 / 없는지를 결정하는 데 도움

- 기능: 뉴런이 신경망을 통해 정보를 처리하고 전달하는 메커니즘

- Sigmoid, tanh, ReLU, ...

## 활성화 기능이 필요한 이유

- 전달하려는 뉴런 값이, 음의 무한대에서 양의 무한대 까지 사용할 수 있다면..

    - 뉴런에 신호 전달할 필요가 있는지? 없는지? 결정할 수가 없다..

- 데이터를 비선형으로 바꾸어 -> 망이 깊어질 수 있도록 도움

- 선형 시스템의 경우 -> 망이 깊어지더라도 -> 1개의 은닉층으로 구현 가능

- 즉, 모델의 표현력을 향상 시켜줌

## 활성화 함수 종류

05 ANN에서 한 번 씩 봤던 내용들이네요?!

# 딥러닝의 기술 혁신

- 딥러닝은 새로 창안된 이론이나 원리 자체는 빈약했음

    - 신경망의 구조와 동작, 학습 알고리즘의 기본 원리는 거의 그대로

- 딥러닝의 기술 혁신 요인

    - 값싼 GPU 등장

        - 10~100배의 속도 향상으로, 학습 시간 단축

    - 데이터셋 커짐

        - 인터넷을 통한 데이터 수집

        - 레이블링 까지..

        - 1,400만장을 담은 ImageNet

    - 학습 알고리즘의 발전

        - ReLU 활성 함수

        - 규제 기법

            - 가중치 감쇠

            - 드롭아웃

            - 조기 멈춤

            - 데이터 중대

            - 앙상블 등
        
        - 다양한 손실 함수와 옵티마이저 개발

- 딥러닝으로 인한 인공지능의 획기적 발전

    - 2010년대에, 딥러닝의 성공 사례 발표 -> AlexNet

    - 고전적인 기계학습을 사용하던 연구 그룹이 딥러닝으로 전환

    - 낮은 성능 때문에.. 대학 실험실에 머물던 프로토타입 시스템에 획기적인 성능 향상

    - 뛰어난 인공지능 제품이 -> 시장에 속속 등장 -> '인공지능 붐' 조성

    - 딥러닝은 인공지능을 구현하는 핵심 기술로 자리잡음

    - 한계로는..

        - 블랙박스

        - 연산 속도

            - 컴퓨팅 파워가 좋음에도

- AlexNet이 나오고 나서.. 다음에 죽죽죽 나온거라네요

- ImageNet 페이페이리

# 딥러닝 소프트웨어

- 현재는 텐서플로와 파이토치가 대세

- 텐서플로는 기업, 파이토치는 대학 연구자들이 많이 사용

- 둘 다 전이학습을 지원 한대용

# 과적합 문제

- Overfitting

- 모델이 학습 데이터에 지나치게 맞추어진 상태

- 데이터에는 잡음이나 오류가 포함

    - 과적합된 모델은.. 학습되지 않은 데이터에 대해 성능 저하

- 과적합 문제 완화 기법

    - 규제화

    - 배치 정규화

    - 드롭아웃

## 규제화

- Regularization

- 오차 함수를 오차 error 항과 모델 복잡도 model complexity 항으로 정의

    - 모델이 복잡해 지면 -> 과적합이 될 수 있으므로 -> 모델 복잡도를 벌점 penalty 항으로 추가

    - 오차 함수를 가지고 계산한 모델은..

        - 별로 fancy 하지 않대요

        - novelty 하지 않아요

## 미니 배치

- minibatch

- 전체 학습 데이터를 일정 크기로 나누어 놓은 것

- 학습 데이터가 큰 경우에는 미니배치 단위로 학습

    - 큰 사이즈의 데이터를 한 번에 학습시키는 것으 오래 걸림..

- 경사 하강법

- 미니 배치를 사용하여 데이터에 포함된 오류에 대해 -> 둔감한 학습 가능

    - 과적합 문제 완화에 도움

## 배치 정규화

- batch nomalization

- 신경망의 각 layer에서 -> 데이터 배치의 분포를 정규화 하는 작업

    - 깊은 신경망 일수록, 같은 input 값을 갖더라도, 가중치가 조금만 달라지면 완전히 다른 출력 값을 얻을 수 있음

- 장점

    - 가중치 초깃값 선택의 의존성이 적어짐

    - 학습 할 때마다, 출력 값을 정규화 해 줌

    - 과적합 위험을 줄일 수 있음

    - 기울기 소멸 문제 해결

    - 학습 속도 개선

- 신경망의 미니배치 B의 각 데이터에 가중치 연산을 적용한 결과인 x<sub>i</sub>의 분포를 정규화 하는 것

- 가중치 적용 -> 평균, 표준편차 계산 -> 크기조정, 이동 파라미터 적용 -> ReLU 적용

## 드롭아웃

- dropout

- 일정 확률로 노드들을 무작위로 선택하여 -> 선택된 노드의 앞뒤로 연결된 가중치 연결선을 없는 것으로 간주하고 학습

- 미니배치나 학습주기(epoch) 마다 드롭아웃 함

- 즉, 없는 것으로 간주할 노드들을 새롭게 선택하여 학습

- 너무 학습이 빨리 되거나, 오버피팅이 일어났을 때.. 드롭아웃을 해보라고 하셨네요

# 딥러닝 설계

- 딥러닝 아키텍쳐의 설계 방향은.. -> 정확성과 효율성을 최적화에 중점

- 정확성

    - 딥러닝에 숨겨진 층에 내재된 hyperparameter의 수가 중요하며

    - 이것을 효율적으로 학습 및 평가 할 수 있도록 설계 필요

    - 숨겨진 층이 많아지면 -> 평가 및 학습 시간이 많아지므로 -> 이를 효율적으로 분배 및 설계해야 하는 것이 딥러닝 설계의 최대의 관건

- 계산 능력

    - 딥러닝은 학습 중에 메모리 및 컴퓨팅 요구사항이 매우 큼

    - 모바일에 로컬로 실행할 모델을 배포하려는 경우에도 -> 최종 학습된 모델의 크기를 고려 필요

- 딥러닝 설계 시 알아 두어야 하는 사항

    - 딥러닝 모델의 각 레이어는 weight와 bias 로 구성..

    - weight와 bias 들은 딥러닝 모델이 => 보다 높은 정확도를 가지이 위하여 -> 훈련하는 동안 지속적으로 수정

    - weight와 bias 는 각각 행렬로 구성

    - 각 iteration 별로 변화되는 양을 learning rate 라고 하며, 이를 hyper parameter에 속함

```
Hyper parameter 

 

배치노말리제이션어쩌구 하고 ㄷㅡ롭아웃 어쩌구 하고 

 

마지막에 softmax layer를 거치면서 확률적으로 나오는 겁ㄴㅣ다.. 

이것이 닭가슴살일 확률이 몇 퍼센트 -> 이런거 
```

- 훈련이 된 딥러닝 모델이 포함하는 것..

    - 각 레이어 들을 서술한 네트워크 정의 파일

    - 해당 신경망 내에 각 레이어에 대한 weight와 bias 정보

# 딥러닝 아킻텍처 예시

- 심층 순방향 신경망 DFN

    - deep feedforward network

    - 딥러닝에서 가장 기본적으로 사용하는 인공신경망

        - 심층신경망 이라고도 부름

    - DFN은 입력층, 은닉층, 출력층 으로 이루어져 있고

        - 이 떄 중요한 것.. 은닉층은 `2개 이상`이어야 한다는 점

    - 순방향이라 부르는 이유:

        - 데이터가 입력층 -> 은닉층 -> 출력층 순으로 전파되므로..

    - DFN의 은닉층이 수십 개에서 수백 개라고 할 때

        - 입력 데이터가 시간 순서에 따른 종속성을 가질 경우

        - 시계열 데이터 처리에 한계가 있음

            - 시간의 흐름에 따라 수집되는 데이터

    - 그래서 이러한 문제점을 해결하기 위해 제안된 것이 `순환신경망`

- 순환 신경망 RNN

    - recurrent neural network

    - 시계열 데이터와 같이, 시간적으로 연속성이 있는 데이터를 처리하기 위해 고안된 인공신경망

        - 시계열 데이터: 일정한 시간 동안 관측되고 수집된 데이터
    
    - 시계열 데이터가 딥러닝 신경망의 입력값으로 사용될 때,

        - 데이터의 특성상 앞에 입력된 데이터가 뒤에 입력된 데이터에 영향을 미침

    - 그래서 -> DFN으로는 시계열 데이터를 정확히 예측할 수 없음

    - RNN vs DFN

        - RNN은 은닉층의 각 뉴런에 순환 구조를 추가하여 -> 이전에 입력된 데이터가 현재 데이터를 예측할 때 다시 사용될 수 있도록 함

        - 따라서, 현재 데이터를 분석할 때 과거 데이터를 고려한 `정확한 데이터 예측`
    
    - 일부 레이어들의 출력 값을 다시 같은 레이어의 입력으로 전달되는 구조

        - 레이어의 노드들은 방향을 가진 엣지로 연결된 -> 순환 구조

    - `memory`의 개념을 가진 모델

    - 시계열, 신호 등의 구간이 존재하는 데이터의 학습에 용이함

    - 하지만.. RNN 역시 신경망 층이 깊어질수록 -> 먼 과거의 데이터가 현재에 영향을 미치지 못하는 문제 발생

    - 이를 `장기 의존성(Long-Term Dependency)` 문제라고 하며, 이를 해결하기 위해 제안된 것이 `LSTM`

- LSTM

    - Long Short-Term Memory

    - RNN과 다르게, 신경망 내에 메모리를 두어 -> 먼 과거의 데이터도 저장할 수 있도록 함

    - 입출력을 제어하기 위한 소자를 두었는데 -> 이것을 gate 라고 함

        - 입력 게이트, 출력 게이트, 망각 게이트

            - 입력 게이트: 현재의 정보를 기억하기 위한 소자.. 과거와 현재 데이터가 시그모이드 함수와 하이퍼볼릭 탄젠트 함수를 거치면서 -> 현재 정보에 대한 보존량을 결정

            - 출력 게이트: 과거의 정보를 어느 정도까지 기억할지 결정하는 소자

            - 망각 게이트: 출력층으로 출력할 정보의 양을 결정하는 소자.. 필요 없는 데이터는 망각해줌

- 합성곱 신경망 CNN

    - convolutional neural network

    - 인간의 시각 처리 방식을 모방한 신경망

    - 이미지 처리가 가능하도록 -> 합성곱 연산 도입

    - 데이터를 구성하는 같은 크기의 일정한 영역들에 대해 -> 작은 특징에서 큰 특징으로 추상화

    - 필터를 통해 특징을 추출하여 -> 하나의 convolutional layer를 만들고

        - 이 특징들에서 좀 더 복잡한 특징을 추출하는 새로운 레이어를 추가하는 방식

    - 여러 개의 convolutional layer들을 연결하고 -> 마지막에는 back propagation을 통해 -> 파라미터 업데이트 -> 학습

    - 주로 이미지 인식에 많이 사용되는 기법

    - 구조

        - 합성곱층

            - 이미지를 분류하는 데 필요한 특징 정보들을 추출하는 역할

            - 특징 정보는 필터를 이용해 추출
            
            - 합성곱층에 필터가 적용되면 -> 이미지의 특징들이 추출된 `특성 맵`이라는 결과를 얻을 수 있음

        - 풀링층

            - 합성곱층의 출력 데이터(특성 맵)을 입력으로 받아서

            - 출력 데이터인 활성화 맵의 크기를 줄이건 특정 데이터를 강조하는 용도로 사용

            - 풀링층을 처리하는 방법: 최대 풀링, 평균 풀링, 최소 풀링

            - 정사각행렬의 특정 영역에서 최댓값을 찾거나 평균값을 구하는 방식으로 동작함

        - 완전연결층

            - 합성곱층과 풀링층으로 추출한 특징을 `분류`하는 역할

            - CNN은 합성곱층에서 특징만 학습하기 때문에 -> DFN이나 RNN에 비해 학습해야 하는 가중치의 수가 적어 -> 학습 및 예측이 빠르다

            - 최근에는 CNN의 강력한 예측 성능과 계산상의 효율성을 바탕으로 이미지 뿐만 아니라 -> 시계열 데이터에도 적용해 보는 연구가 활발히 진행 중

- 적대적 생성 신경망 GAN

    - generative adverarial network

    - 2개의 신경망 모델이 서로 경쟁하면서 -> 더 나은 결과를 만들어 내는 `강화학습`

    - 특히, 이미지 생성 분야에서 뛰어난 성능

        - 기존의 인공신경망과는 다르게 -> 두 개의 인공신경망이 서로 `경쟁`

    - 이를 생성 모델과 판별 모델 이라고 하며.. -> 각각은 서로 다른 목적을 가지고 학습

        - 생성 모델: 주어진 데이터와 최대한 유사한 가짜 데이터를 생성

        - 판별 모델: 진짜 데이터와 가짜 데이터 중 어떤 것이 진짜 데이터 인지 판별

# 딥러닝 응용 사례

```
강의자료 p68 부터..
```
