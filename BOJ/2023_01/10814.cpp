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