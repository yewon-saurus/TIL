#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> v;

    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.emplace_back(tmp);
    }

    int cnt = 0; // 동전 갯수
    while (1) {
        cnt += k / v.back();
        k -= (k / v.back()) * v.back();
        
        v.pop_back();
        
        if (k <= 0) {
            cout << cnt << "\n";
            return 0;
        }
    }
}