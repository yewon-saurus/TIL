#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    map<string, int> m;
    string tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;

        if (m.find(tmp) != m.end()) {
            m[tmp]++;
        }
        else {
            m.emplace(tmp, 0);
        }
    }

    string top;
    int result = 0;
    for (auto i = m.begin(); i != m.end(); i++) {
        result = max(result, i->second);
    }

    for (auto i = m.begin(); i != m.end(); i++) {
        if (result == i->second) {
            cout << i->first;
            return 0;
        }
    }

    return 0;
}