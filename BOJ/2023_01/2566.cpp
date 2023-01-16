#include <iostream>

using namespace std;

int main() {
    int arr[9][9];
    
    int tmp;
    int max = 0;
    int where[2];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> tmp;
            if (tmp >= max) {
                max = tmp;
                where[0] = i + 1;
                where[1] = j + 1;
            }
        }
    }

    cout << max << '\n' << where[0] << ' ' << where[1];

    return 0;
}