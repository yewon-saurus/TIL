#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;

    int tmp;
    int cnt = 0; // 나눠지는 수 몇 개?
    int result = 0; // 소수 몇 개?
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        
        for (int j = 1; j <= tmp; j++) {
            if (tmp % j == 0) {
                cnt++;
                continue;
            }
        }
        if (cnt == 2) {
            result++;
        }
        cnt = 0;
    }

    cout << result << "\n";
    return 0;
}