#include <iostream>
#include <string>

using namespace std;

int main() {
    string s = "";
    cin >> s;

    int result = 0;
    bool isMinus = false;
    string tmp = "";
    for (int i = 0; i <= s.length(); i++) {
        if (s[i] == '-' || s[i] == '+' || i == s.length()) {
            if (isMinus) {
                result -= stoi(tmp);
                tmp = "";
                // isMinus = false;
            }
            else {
                result += stoi(tmp);
                tmp = "";
            }
        }
        else {
            tmp += s[i];
        }

        if (s[i] == '-') {
            isMinus = true;
        }
    }

    cout << result << "\n";
}