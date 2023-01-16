#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> arr;
    int a, b;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;

        arr.emplace_back(pair<int, int>(a, b));
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        cout << arr[i].first << " " << arr[i].second << "\n";
    }

    return 0;
}