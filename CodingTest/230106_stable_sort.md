# stable_sort() 란?

STL의 algorithm 헤더파일에

대표적인 정렬 함수로 sort가 있죠

실제로 이 함수를 유용하게 쓴답니다(저 진심 레알 많이 씀..)

근데 `stable_sort()`는 뭐가 다른 걸까요?

- `stable_sort()`는

    - 비교를 할 때, 같은 조건일 경우에 처리하는 방법이 다름

```
1 5
1 2
2 2
3 4
```

- 이런 데이터가 있을 때

    - 첫 번째 원소를 기준으로 정렬이 된 데이터 인데요

    - 첫 번째 원소를 기준으로..?! -> 그럼 첫 번째 원소가 같을 때는 어떻게 되는걸까?

        - 첫 번째 원소가 1 일때는, 어떤 인덱스가 앞에 올 지 예상할 수 없는데요

        - 이게 `불안정 정렬` 이라네요

- `stable_sort()`는 여러 값들이 묶여 있을 때,

    - 하나의 요소로 정렬을 했을 때,

    - 다른 요소들의 정렬 순서도 정렬 전과 같이

    - `그대로 유지할 수 있도록 하는` 정렬

        - 하나의 요소를 조건으로 정렬을 할 때

        - 조건이 같다면

        - 기존 정렬 순서를 유지
        
        - 즉, 예측할 수 있는 `안정적인 정렬`인 것!
        
- `stable_sort()`가 `sort()`보다 빠르며, 유용하게 쓰일 때가 있다고 합니다

## 사용 예

BOJ 10814번: 나이순 정렬

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, string>> v;
    pair<int, string> tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp.first >> tmp.second;
        v.emplace_back(tmp);
    }

    stable_sort(v.begin(), v.end(), comp);

    for (int i = 0; i < n; i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
}
```

# References

🔗[[C++] stable_sort 이란? :: tistory 통통푸딩](https://codingwell.tistory.com/44)