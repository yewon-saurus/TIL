#include <iostream>
#include <map>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    map<int, bool> m;
    int tmp;
    for (int i = 0; i < A + B; i++) {
        cin >> tmp;
        if (m[tmp] == true) {
            // 이미 m에 tmp가 존재하면
            // m에서 해당 값 삭제
            m.erase(tmp);
        }
        else {
            // 아니면 추가
            m[tmp] = true;
        }
    }

    cout << m.size();

    return 0;
}