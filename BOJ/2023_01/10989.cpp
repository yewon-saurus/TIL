#include <iostream>

using namespace std;

int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    // 입력받은 수를 전부 저장하게 되면
    // 제한된 메모리를 초과해버림
    // 숫자를 카운트 해두었다가, 출력만 해주는 방식을 이용

    int arr[10001] = {0};

    // 숫자 개수 카운트
    for(int i = 0 ; i < T; i++) {
        int a;
        cin >> a;
        arr[a] += 1;
    }

    // 각 숫자를 개수만큼 출력해주기
    for(int i = 1 ; i <= 10000; i++) {
        for (int j = 0; j < arr[i]; j++) {
            cout << i << "\n";
        }
    }
}