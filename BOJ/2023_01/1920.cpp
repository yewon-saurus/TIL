#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N, M;
    cin >> N;

    int tmp;
    vector<int> v;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        v.emplace_back(tmp);
    }

    sort(v.begin(), v.end());

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        
        if (binary_search(v.begin(), v.end(), tmp) == 1) {
            cout << 1 << '\n';
        }
        else {
            cout << 0 << '\n';
        }
    }

    return 0;
}