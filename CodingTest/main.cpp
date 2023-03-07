#include <iostream>
#include <set>
using namespace std;

// 서로 다른 부분 문자열의 개수
// 11478 - S3
// https://www.acmicpc.net/problem/11478

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string S;
    cin >> S;

    set<string> set;

    string tmp;
    for (int i = 0; i < S.length(); i++) {
        tmp = "";
        for (int j = i; j < S.length(); j++) {
            tmp += S[j];
            set.insert(tmp);
        }
    }

    cout << set.size();
    return 0;
}