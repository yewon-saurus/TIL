#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int len, tmp;
    vector<int> v;
    
    cin >> len;
    while (len--) {
        cin >> tmp;
        v.emplace_back(tmp);
    }

    sort(v.begin(), v.end());
    
    cin >> len;
    while (len--) {
        cin >> tmp;
        cout << binary_search(v.begin(), v.end(), tmp) << ' ';
    }
}