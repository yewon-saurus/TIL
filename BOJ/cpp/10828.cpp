#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> stack;
    string cmd;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> cmd;

        if (!(cmd.compare("push"))) {
            // compare()
            // 값이 서로 같다면 0을, 다르다면 -1을 return
            cin >> tmp;
            stack.emplace_back(tmp);
        }
        else if (!(cmd.compare("top"))) {
            if (stack.empty()) {
                cout << "-1" << "\n";
            }
            else {
                cout << stack.back() << "\n";
            }
        }
        else if (!(cmd.compare("size"))) {
            cout << stack.size() << "\n";
        }
        else if (!(cmd.compare("empty"))) {
            if (stack.empty()) {
                cout << "1" << "\n";
            }
            else {
                cout << "0" << "\n";
            }
        }
        else if (!(cmd.compare("pop"))) {
            if (stack.empty()) {
                cout << "-1" << "\n";
            }
            else {
                cout << stack.back() << "\n";
                stack.pop_back();
            }
        }
    }

    return 0;
}