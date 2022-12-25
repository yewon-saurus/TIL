#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n[5];
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        cin >> n[i];
        sum += n[i];
    }

    sort(n, n+5);

    cout << sum / 5 << "\n";
    cout << n[2];
}