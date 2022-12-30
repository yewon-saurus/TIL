#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;

    int tmp;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp;

        if (tmp == 0) {
            sum -= v.back();
            v.pop_back();
        }
        else {
            v.emplace_back(tmp);
            sum += tmp;
        }
    }

    cout << sum << "\n";
    return 0;
}