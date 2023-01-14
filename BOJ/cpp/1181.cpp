#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string a, const string b) {
    if (a.length() == b.length()) {
        return a < b;
    }
    return a.length() < b.length();
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin >> N;

    vector<string> v;
    string tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        if (find(v.begin(), v.end(), tmp) == v.end()) {
            // 중복된 경우, 하나만 출력하게 해야 하므로
            // 중복된 게 있으면 아에 push를 안하게
            // find 함수는 해당 단어가 존재하지 않을 경우, vector end()를 반환함
            v.emplace_back(tmp);
        }
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }

    return 0;
}