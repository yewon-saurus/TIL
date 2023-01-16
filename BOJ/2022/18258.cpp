#include <iostream>
#include <queue>

using namespace std;

int main() {
    // 빠른 입출력을 위한 처리 라는데..
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin >> n;

    string s;
    int number;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        cin >> s;

        if (s == "push") {
            cin >> number;
            q.push(number);
        }
        else if (s == "pop") {
            if (q.empty()) {
                cout << "-1" << "\n";
            }
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if (s == "size") {
            cout << q.size() << "\n";
        }
        else if (s == "empty") {
            if (q.empty()) {
                cout << "1" << "\n";
            }
            else {
                cout << "0" << "\n";
            }
        }
        else if (s == "front") {
            if (q.empty()) {
                cout << "-1" << "\n";
            }
            else {
                cout << q.front() << "\n";
            }
        }
        else if (s == "back") {
            if (q.empty()) {
                cout << "-1" << "\n";
            }
            else {
                cout << q.back() << "\n";
            }
        }
    }
}