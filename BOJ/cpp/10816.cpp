#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, m;
    
    cin >> n;
    vector<int> v;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.emplace_back(tmp);
    }

    sort(v.begin(), v.end());

    cin >> m;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        cout << upper_bound(v.begin(), v.end(), num) - lower_bound(v.begin(), v.end(), num) << ' ';
    }
}