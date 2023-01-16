#include <iostream>

using namespace std;

int arr[100][100]; // 얘가 전역변수로 있어야 정답처리가 되네요
int main() {
    int n;
    cin >> n;

    int x, y, cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        for (int j = y; j < y + 10; j++) {
            for (int k = x; k < x + 10; k++) {
                if (!arr[j][k]) {
                    cnt++;
                    arr[j][k] = 1;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}