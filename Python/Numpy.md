```
import numpy as np
```

# Numpy 기초

## 배열 만들기

```
np.array()
```

```
a1 = [1, 2, 3, 4, 5] # 리스트를 만들고
b1 = np.array(a1)

# 2차원 배열
a2 = [
  [1.5, 2.5, 3.2],
  [4.2, 5.7, 6.4],
]
b2 = np.array(a2)

# 3차원도 마찬가지겠죠?
```

### 배열 정보 확인

- 차원 확인
- 형태(크기) 확인
- 요소 자료형 확인

#### 차원 확인

```
print(b1.ndim) # 1
print(b2.ndim) # 2
```

#### 형태(크기) 확인

```
print(b1.shape) # (5, )
print(b2.shape) # (2, 3)
```

#### 요소 자료형 확인

```
print(b1.dtype)
print(b2.dtype)
```

### Reshape

```
a = np.array(
  [
    [1, 2, 3,],
    [4, 5, 6,],
  ]
)

b = a.reshape(3, 2)

c = a.reshape(1. -1) # 아~ 얘도 -1 이용해서 이런식으로 할 수 있군
```

## 배열 인덱싱과 슬라이싱

```
a = np.array([
  [1, 2, 3,],
  [4, 5, 6],
  [7, 8, 9,],
])

print(a[[0], [1]]) # array([2])
print(a[0, 1]) # 2

print(a[0:2]) # [[1 2 3]
                 [4 5 6]]
print(a[0, 0:2]) # [1 2]
```

## 조건 조회

- 조건에 맞는 요소를 선택

```
score = np.array([
  [78, 91, 84, 89, 93, 65],
  [82, 87, 96, 79, 91, 73,]
])

print(score[score >= 90 ])

# 또는 이렇게도 됨
condition = score >= 90
print(score[condition])

# 여러 조건을 연결하여 조회도 가능
print(score[(score >= 90) & (score <= 95)])
```

## 배열 연산

- 더하기, 빼기, 곱하기, 나누기
- 행렬 곱, 행렬 합(여기선 우선 생략)

```
# 더하기
print(x + y)
print(np.add(x, y))

# 빼기
print(x - y)
print(np.subtract(x, y))

# 곱하기
print(x * y)
print(np.multiply(x, y))

# 배열 나누기
print(x / y)
print(np.divide(x, y))

# 지수 연산
print(x ** y)
print(np.power(x, y))
```

## 배열 집계

```
a = np.array([1, 5, 7,], [2, 3, 8,])

# 전체 집계
print(np.sum(a)) # 26

# 열 기준 집계
print(np.sum(a, axis=0)) # [3 8 15]

# 행 기준 집계
print(np.sum(a, axis=1)) # [13 13]
```

## 자주 사용되는 함수들 - np.argmax(), np.argmin(), np.where

- 최대값의 **인덱스**

```
a = np.array([1, 5, 7,], [2, 3, 8,])

print(np.argmax(a)) # 5
print(np.argmax(a, axis=0)) # [1 0 1] # 행 방향 최대값의 인덱스
print(np.argmax(a, axis=1) # [2 2] # 열 방향 최대값의 인덱스
```

```
a = np.array(1, 3, 2, 7,])
print(np.where(a > 2, 1, 0)) # array([0, 1, 0, 1])
```
