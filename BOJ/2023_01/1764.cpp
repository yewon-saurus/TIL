#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    string tmp;
    vector<string> v, answer;

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.emplace_back(tmp);
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++) {
        cin >> tmp;
        if (binary_search(v.begin(), v.end(), tmp)) {
            answer.emplace_back(tmp);
        }
    }

    sort(answer.begin(), answer.end()); // 다시 정렬(안 하면 틀렸습니다 뜸)

    cout << answer.size() << '\n';
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << '\n';
    }
}