vector는 우선..

C++ 표준 라이브러리에 있는 컨테이너로,

사용자가 사용하기 편하게 정의된 class 라고 하네요..

vector를 생성하면 메모리 heap에 생성되고, 동적할당 됨

속도 측면에서 성능은 array에 비해 떨어지지만

메모리를 효율적으로 관리, 예외처리가 쉽게 됨..

```C
vector<int> v;

vector<int>v(4);
// int형 벡터 생성 후, 크기를 4로 할당.. 모든 벡터 요소는 0으로 초기화 됨

vector<int>v = {1, 2, 3}
// int형 벡터 생성 후 1, 2, 3으로 초기화

vector<int>v[] = {{1, 2}, {3, 4}};
// int형 벡터 배열 생성
// 행은 가변, 열은 고정

vector<vector<int>> v;
// 2차원 벡터 생성
// 행, 열 모두 가변

vector<int> v = {1, 2, 3, 4, 5};
v.assign(5, 10);
// 벡터 범위를 5로 정하고
// 정수 10으로 쵝화
// assign 맡기다, 선임하다, 파견하다..
```

## Vactor의 Iterators

`v.begin()`: 벡터 `시작점`의 `주소값` 반환

`v.end()`: 벡터 `끝부분 + 1`의 `주소값` 반환

`v.rbegin()`: reverse begin: 벡터의 `끝` 지점을 시작점으로 반환

`v.rend()`: reverse end: 벡터의 `시작 + 1` 지점을 끝 부분으로 반환

## Vector Element access 벡터의 요소 접근

`v.at(i)`: 벡터의 i번째 요소 접근..

    - 범위 검사 함

`v.[i]`: 벡터의 i번째 요소 접근..

    - 범위 검사 안 함

`v.front()`: 벡터의 첫 번째 요소 접근

`v.back()`: 벡터의 마지막 요소 접근

```
Vector의 at과 []에 대한 차이점!!

둘 다 똑같이, N번째 요소 접근 이지만..

at은 범위를 검사하여 -> 범위 밖의 요소에 접근 시 -> 예외처리를 발생


근데?

[]는.. 범위 검사를 하지 않으며, 예외처리를 발생시키지 않는다.

해당 범위 밖의 요소에 접근 시도 시 -> 일반적인 디버깅(g++, VC++)이 발생



벡터는 효율을 중점으로 둔 라이브러리 함수..

보통 []를 권장하고 있구요

여러가지 방법으로 따로 유효성 검사가 가능해서

[]를 많이 사용한대요~

```

```c
vector<int> v = {1, 2, 3, 4};

cout << v.front() << endl; // 1
cout << v.back() << endl; // 4
cout << v.at(1) << endl; // 2
cout << v.[2] << endl; // 3
```

## Vector에 요소 삽입

`v.push_back()`: 벡터의 마지막 부분에 새로운 요소 추가

`v.pop_back()`: 벡터의 마지막 부분 제거

`v.insert(삽입할 위치의 주소 값, 변수값)`: 사용자가 원하는 위치에 요소 삽입

`v.emplace(삽입할 위치의 주소 값, 변수값)`: 사용자가 원하는 위치에 요소 삽입

    - 근데, 이 때, move로 인해 복사 생성자 X

`v.emplace_back()`: 벡터의 마지막 부분에 새로운 요소 추가

    - 이 때도 move로 인해, 복사 생성자 X

`v.erase(삭제할 위치)` or `v.erase(시작위치, 끝위치)`: 사용자가 원하는 index 값의 요소를 지운다..

`v.clear()`: 벡터의 모든 요소를 지운다.. -> return size = 0

`v.resize(수정값)`: 벡터의 사이즈를 조정

    - 범위 초과 시, 0으로 초기화

`v.swap(벡터 변수)`: 벡터와 벡터 간 스왑

```c
#include <vector>

int main(){
    vector<int> v;

    v.push_back(10);
    v.push_back(20);        //v = { 10, 20 }

    v.inset(v.begin() + 1, 100);     // v = { 10, 100, 20 }

    v.pop_back();        // v = { 10, 100 }

    v.emplace_back(1); //v = { 10, 100, 1 }
    v.emplace_back(2);    //v = { 10, 100, 1, 2 }
    v.emplace(v.begin() + 2, -50);    //v = { 1, 100, -50, 1, 2 }

    v.erase(v.begin() + 1); // v = { 1, -50, 1, 2 }
    v.resize(6);    // v = { 1, -50, 1, 2, 0, 0 }
    v.clear();    // v = empty()     
}
```

```
잠깐!!

vector에 대한 복사 생성자와 move?

기본적으로 push_back() 함수는 값을 넣는 과정에서, 복사생성자를 호출하게 됩니다.

뿐만 아니라, insert를 하게 된다면 -> 모든 값들을 새로운 메모리에 복사한 후 -> 해당 자리에 값을 넣게 되는데(일반적인 배열 중간에 값을 끼워넣기 과정과 같음)

이렇게 되면? 복사생성자로 인한 오버헤드가 커지게 되며 -> 성능 저하를 야기..

그래서 나온 것이 emplace, emplace_back 이구나~

emplace, emplace_back은 벡터 내부에서 값들을 생성하거든요

즉, 생성자만 호출이 된다는 말씀
```

그리고

vector에는 `size()`와 `capacity()`가 있는데

`size()`는 벡터가 생성된 크기

`capacity()`는 벡터의 최대 할당 크기 라고 하네요

```
벡터의 크기가 capacity()의 크기를 초과해 버리면

reallocate가 발생하는데

그러면? 모든 값들을 새로운 메모리 공간에 복사한 후, 기존의 벡터를 파괴하는 과정이 발생하고요?

여기서 복사 과정에서도, 복사 생성자가 발생해서

프로그램의 퍼포먼스가 저하된다..



또한 reallocate가 자주 일어나는 현상을 막기 위해

reverse()라는 함수를 이용하면 되는데요

이 함수는 벡터의 capacity() 크기를 설정해주는 함수로

충분한 벡터를 만들어서, 불필요한 생성 과정을 없애주는 역할을 하죠

하지만

reverse()를 너무 크게 잡게되면, 벡터가 불필요하게 늘어나..

메모리를 많이 잡아먹을 수 있으니!

남은 공간을 잡아주는 함수가 바로 shrink_to_fit() 이라는 함수
```

clear() 에 대한 설명

clear()로 벡터의 값들을 지우게 되면

벡터의 요소들은 없어지지만, capacity()는 남아 있게 되는데요

clear()로 벡터의 값을 지운 후, 다시 사용하지 않는다면?

어이쿠 여기 벡터 메모리 공간이 잉여로 남았어요

이 때 sweap을 이용한 방법을 써볼까요?

```c
vector<int> v = {1, 2, 3, 4};
v.clear();
cout << v.capacity() << endl; // 10

vector<int>().swap(v);
cout << v.capacity() << endl; // 0
```

이렇게 하면

아무것도 없는 벡터 공간과 swap이 일어나, capacity() 공간을 없앨 수 있습니다..

하지만 함수가 끝나면

자동으로 heap에서 메모리 해제가 되니까

한 개의 함수에서 벡터를 계속 재활용해 사용하지 않는 이상..

굳이 싶은 방법입니다요

## Vector Capacity 벡터 용량

`v.empty()`: 벡터가 빈공간이라면 true, 값이 뭐라도 있다면 false

`v.size()`: 벡터의 크기 반환

`v.capacity()`: heap에 할당된 벡터의 실제 크기(최대크기) 반환

`v.max_size()`: 벡터가 system에서 만들어질 수 있는 최대 크기 반환

`v.reverse(숫자)`: 벡터의 크기 설정

    - reserve 예약하다, 비축, ...

`v.shrink_to_fit()`: capacity의 크기를 벡터의 실제 크기에 맞춤

    - shrink 줄어들다, 수축

```c
vector<int>v = { 1, 2, 3, 4 };

cout << v.size() << endl;    //output : 4
cout << v.capacity() << endl; //output : 10 (컴파일 환경에 따라 달라질 수 있음)

v.reserve(6);
cout << v.capacity() << endl; //output : 6
cout << v.max_size() << endl; //output : 1073741823(시스템 성능에 따라 달라질 수 있음)

v.shrink_to_fit();
cout << v.capacity() << endl; //output : 4

cout << v.empty() << endl; //output : false
v.clear();
cout << v.empty() << endl; //output : true​
```
