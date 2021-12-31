#include<iostream>
using namespace std;
int main() {
    int howMany;

    cin >> howMany;
    
    double *score = new double[howMany];
    double max = 0;
    for (int i = 0; i < howMany; i++) {
        cin >> score[i];
        if (max < score[i]) {
            max = score[i];
        }
    }

    double sum = 0;
    
    for (int i = 0; i < howMany; i++) {
        score[i] = score[i] / max * 100;
        sum += score[i];
    }

    double avg = sum / howMany;

    cout << avg;
}