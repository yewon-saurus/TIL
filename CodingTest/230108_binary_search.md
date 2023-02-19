# C++ 이진탐색 STL

binary_search, upper_bound, lower_bound

## binary_search

- binary_search는

    - 인자로 `배열의 시작 주소`, `시작 주소 + 배열 크기`, `val`을 받습니다

    - 벡터도 마찬가지

- binary_search와 upper_bound, lower_bound는

    - 먼저 sort를 해주고 써야 합니다

```cpp
binary_search(arr, arr + n, val);
```

- return 값은 1(true) 혹은 0(false) 이며,

    - val이 arr ~ arr + n 사이에 `있는 경우가 1`

    - 없는 경우가 0

## upper_bound, lower_bound

- 만약, val과 일치하는 값이

    - `몇 개나 있는지` 알아보고 싶으면?

    - 이럴 때 사용할 수 있는 STL이 바로 `upper_bound`와 `lower_bound`

```cpp
upper_bound(arr, arr + n, val);
```

- 리턴 값의 경우, `upper`인지 `lower`인지에 따라 값이 조금 다른데,

    - upper_bound의 경우

        - val이 담긴 마지막 요소의 다음 주소를 반환하고
    
    - lower_bound의 경우

        - val이 담긴 첫 번째 요소의 주소를 반환

    - 못 찾은 경우

        - 둘 다, 두 번째 인자(`arr + n`)(주소)을 반환
    
이게 무슨 말?

예시)

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int myInts[] = { 10, 20, 30, 30, 20, 10, 10, 20 };

    sort(myInts, myInts + 8); // 먼저 sort 해야한다고 했죠?
    // 10 10 10 20 20 20 30 30

    int *low, *up, *low2, *up2;

    low = lower_bound(myInts, myInts + 8, 77); // 0x7ffe29dd9e20
    up = upper_bound(myInts, myInts + 8, 77); // 0x7ffe29dd9e20
    cout << up - low << '\n'; // 0

    low2 = lower_bound(myInts, myInts + 8, 20); // 0x7ffe29dd9e0c
    up2 = upper_bound(myInts, myInts + 8, 20); // 0x7ffe29dd9e18
    cout << up2 - low2 << '\n'; // 3
}
```

# References

🔗[C++ 이진 탐색 STL binary_search, upper_bound, lower_bound :: tistory](https://42kchoi.tistory.com/194)