#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const char &a, const char &b) {
    return a > b;
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string s;
    cin >> s;

    sort(s.begin(), s.end(), cmp);

    int sum = 0; // 모든 자리의 수의 합이 3의 배수이면, 그 수는 3의 배수
    if (s.back() == '0') {
        for (int i = 0; i < s.size(); i++) {
            sum += s[i];
        }

        if (sum % 3 == 0) {
            cout << s;
        }
        else {
            cout << -1;
        }
    }
    else {
        cout << -1;
    }
    
    return 0;
}