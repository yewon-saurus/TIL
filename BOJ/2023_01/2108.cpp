#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool comp (const pair<int, int> &p1, const pair<int, int> &p2) {
    if (p1.second == p2.second) { // 빈도수 같으면
        return p1.first < p2.first; // 값이 작은 게 앞으로
    }
    return p1.second > p2.second; // 다르면 빈도수 큰 게 앞으로
}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v;

    double sum = 0; // type 주목
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        sum += tmp;

        v.emplace_back(tmp);
    }

    sort(v.begin(), v.end());

    // 최빈값 구하기
    vector<pair<int, int>> howMany; // number, count
    pair<int, int> cntTmp;
    for (int i = 0; i < n; i++) {
        if (howMany.empty()) {
            howMany.emplace_back(pair<int, int>(v[i], 1));
            continue;
        }
        
        if (howMany.back().first == v[i]) {
            cntTmp = howMany.back();
            cntTmp.second++;
            howMany.pop_back(); // 기존 것 삭제
            howMany.emplace_back(cntTmp); // 새로운 값 다시 삽입
        }
        else {
            howMany.emplace_back(pair<int, int>(v[i], 1));
        }
    }

    sort(howMany.begin(), howMany.end(), comp);

    cout << (int)round(sum / n) << "\n";
    cout << v[n / 2] << "\n";
    
    if (howMany[0].second == howMany[1].second) {
        // 최빈값이 여러개일 때
        cout << howMany[1].first << "\n";
    }
    else {
        cout << howMany[0].first << "\n";
    }

    cout << v.back() - v.front() << "\n";
    
    return 0;
}