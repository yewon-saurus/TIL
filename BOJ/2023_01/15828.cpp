/*
라우터에서는..
먼저 온 패킷부터 하나씩 처리 -> 버퍼에서 제거
*/

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> q;
    int tmp;
    int size;
    while (1) {
        cin >> tmp;
        size = q.size();

        if (tmp == 0) {
            q.pop();
        }
        else if (tmp == -1) {
            if (size == 0) {
                cout << "empty ";
            }
            else {
                for (int i = 0; i < size; i++) {
                    cout << q.front() << ' ';
                    q.pop();
                }
            }
            return 0;
        }
        else if (tmp > 0 && size < N) {
            q.emplace(tmp);
        }
    }
    return 0;
}