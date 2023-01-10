#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s;
    vector<char> stack;
    while (1) {
        getline(cin, s);
        if (s[0] == '.') {
            break;
        }

        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == '(') {
                stack.emplace_back('(');
            }
            if (s[i] == '[') {
                stack.emplace_back('[');
            }
            if (s[i] == ')') {
                if (!stack.empty() && stack.back() == '(') {
                    stack.pop_back();
                }
                else {
                    cout << "no\n";
                    stack.clear();
                    break;
                }
            }
            if (s[i] == ']') {
                if (!stack.empty() && stack.back() == '[') {
                    stack.pop_back();
                }
                else {
                    cout << "no\n";
                    stack.clear();
                    break;
                }
            }

            if (stack.empty() && i == s.length() - 2) {
                // s[s.length() - 1] == '.'
                cout << "yes\n";
            }
            else if (!stack.empty() && i == s.length() - 2) {
                cout << "no\n";
                stack.clear();
            }
        }
    }

    return 0;
}