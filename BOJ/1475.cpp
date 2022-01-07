#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    /*
    0 1 2 3 4 5 6 9 8 7
    6과 9는 서로 뒤집어서 이용 가능
    */

   int digit = 1;
   while ((N / 10) != 0){
       digit++;
       N /= 10;
   }

   cout << digit;
}