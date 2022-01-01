#include<iostream>
using namespace std;

int main() {
    int C;
    cin >> C;

    for (int i = 0; i < C; i++) {
        int N;
        cin >> N;
        double* score = new double[N];
        double sum = 0;
        
        for (int j = 0; j < N; j++) {
            cin >> score[j];

            sum += score[j];
        }
        double avg;
        avg = sum / (double)N;
        
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (avg < score[j]) {
                count++;
            }
        }

        // 소수점 아래 개수 ?
        cout.precision(3);
        cout << fixed;
        cout << count / (double)N * 100 << "%\n";

        delete[] score;
    }
}