#include <iostream>

using namespace std;

long long int memo[90] = {0, };
// 90번째 피보나치 수가 엄청 커서
// long long으로 해줘야 하네요

long long int fibo(int n) {
    if (n == 0) {
        return 0;
    }
    else if (n == 1) {
        return 1;
    }

    if (memo[n] > 0) {
        return memo[n];
    }
    else {
        memo[n] = fibo(n - 1) + fibo(n - 2);
        return memo[n];
    }
}

int main() {
    int n;
    cin >> n;

    cout << fibo(n) << '\n';
}