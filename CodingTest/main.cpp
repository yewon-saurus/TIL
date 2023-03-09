#include <iostream>
#include <algorithm>
using namespace std;

// 최소공배수
// 1934 - B1
// https://www.acmicpc.net/problem/1874

int GCD(int a, int b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int a, b, max;
        cin >> a >> b;
        max = GCD(a, b);

        cout << a * b / max << '\n';
    }

    return 0;
}