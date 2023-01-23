#include <iostream>
using namespace std;

int calc(int a, int b) {
    if (b == 1) return 1;
    if (a == 0) return b;
    return (calc(a - 1, b) + calc(a, b - 1));
}

int main() {
    int T;
    cin >> T;

    for (int test_case = 0; test_case < T; test_case++) {
        int k, n;
        cin >> k >> n;
        cout << calc(k, n) << '\n';
    }

    return 0;
}