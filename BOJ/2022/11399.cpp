#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;

    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.emplace_back(tmp);
    }

    sort(v.begin(), v.end());

    int sum = 0;
    int total = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
        total += sum;
    }

    cout << total << "\n";
}