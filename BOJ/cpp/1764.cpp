#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    string tmp;
    vector<string> v;

    vector<string> answer;
    int cnt = 0;
    for (int i = 0; i < n + m; i++) {
        cin >> tmp;

        for (int j = 0; j < i; j++) {
            if (tmp == v[j]) {
                cnt++;
                answer.emplace_back(tmp);
                continue;
            }
        }
        v.emplace_back(tmp);
    }

    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++) {
        cout << answer[i] << '\n';
    }
}