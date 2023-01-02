#include <iostream>
#include <algorithm>

using namespace std;

bool comp(const char &p1, const char &p2) {
    return p1 > p2;
}

int main() {
    string c;
    cin >> c;

    sort(c.begin(), c.end(), comp);

    cout << c << "\n";
    return 0;
}