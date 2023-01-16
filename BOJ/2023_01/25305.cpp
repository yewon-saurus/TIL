#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int tmp;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.emplace_back(tmp);
    }

    sort(v.begin(), v.end());

    cout << v[n - k] << "\n";
}