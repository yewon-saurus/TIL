#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<pair<int, int>> v;
    vector<int> rank;

    cin >> n;

    pair<int, int> tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp.first >> tmp.second;
        v.emplace_back(tmp);
        rank.emplace_back(1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i].first < v[j].first && v[i].second < v[j].second) {
                rank[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << rank[i] << ' ';
    }
}