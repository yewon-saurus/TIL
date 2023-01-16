#include <iostream>

using namespace std;

int main() {
    int a, b;
    while (1) {
        cin >> a >> b;

        if (a == 0 && b == 0) {
            return 0;
        }

        if (a == 0 || b == 0) {
            cout << "neither\n";
            // Division By Zero
        }
        else {
            if (b % a == 0) {
                cout << "factor\n";
            }
            else if (a % b == 0) {
                cout << "multiple\n";
            }
            else {
                cout << "neither\n";
            }
        }
    }

    return 0;
}