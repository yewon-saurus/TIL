#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int bag[2] = {5, 3};
    // 봉지: 5kg, 3kg

    int howMany = 0;

    while (n >= 0) {
        if (n % bag[0] == 0) {
            howMany += n / bag[0];
            cout << howMany << "\n";
            return 0;
        }
        n -= 3;
        howMany++;
    }

    cout << -1 << "\n";
    return 0;
}