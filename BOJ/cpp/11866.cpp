#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        q.emplace(i);
    }

    cout << '<';

    while (q.size() != 0) {
        for (int i = 1; i < K; i++) {
            q.emplace(q.front());
            q.pop();
            // 맨 앞 숫자를 뒤로 보냄
        }
        cout << q.front();
        if (q.size() != 1) {
            cout << ", ";
        }
        q.pop();
    }
    cout << '>';

    return 0;
}