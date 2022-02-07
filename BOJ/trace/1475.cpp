#include <iostream>
#include <string>

using namespace std;

int digit[10];

int main() {
    string N;
    cin >> N;
    int len = N.length();
    for (int i = 0; i < len; i++) {
        digit[N[i] = '0']++;
    }

    int sixNnine = (digit[6] + digit[9] + 1) / 2;
    digit[6] = sixNnine;
    digit[9] = sixNnine;

    int M = 0;
    for (int i = 0; i < 10; i++) {
        if (digit[M] < digit[i]) {
            M = i;
        }
    }

    cout << digit[M] << "\n";
}