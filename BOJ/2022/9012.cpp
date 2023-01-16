#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<char> stack;
    string tmp;

    for (int i = 0; i < n; i++) {
        cin >> tmp;

        for (int j = 0; j < tmp.length(); j++) {
            if (tmp[j] == '(') {
                stack.emplace_back(tmp[j]);
            }
            else if (tmp[j] == ')') {
                if (stack.empty()) {
                    stack.emplace_back('x');
                    // 의미 없는 값 -> line 32 의 `.empty()` 조건을 피하게
                    break; // 즉시 반복문 종료
                }
                else {
                    stack.pop_back();
                }
            }
        }

        if (stack.empty()) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }

        stack.clear();
    }

    return 0;
}