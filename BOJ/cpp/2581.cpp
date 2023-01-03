#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int cnt = 0;
    vector<int> v;
    int sum = 0;
    for (int i = m; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) {
                cnt++;
                continue;
            }
        }
        if (cnt == 2) {
            v.emplace_back(i);
            sum += i;
        }
        cnt = 0;
    }

    if (v.empty()) {
        cout << "-1" << "\n";
    }
    else {
        cout << sum << "\n";
        cout << v[0] << "\n";
    }
}