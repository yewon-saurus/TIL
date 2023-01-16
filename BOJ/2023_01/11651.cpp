#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> v;
    pair<int, int> tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp.first >> tmp.second;
        v.emplace_back(tmp);
    }

    sort(v.begin(), v.end(), cmp);

    for (int i = 0; i < N; i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }

    return 0;
}