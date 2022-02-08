#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;



int main() {
	char arr[100];
	int score = 0;
	int sum=0;
	int N; // 테스트 케이스 수
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin>>arr;// 배열에 문자열 입력

		for (int j = 0; j < strlen(arr); j++) {
			if (arr[j] == 'O') {
				score++; // 점수 증가
				sum += score; // 점수 누적
				
			}
			if (arr[j] == 'X') {
				score = 0; // 점수 초기화
			}
		}
		cout << sum<<endl;
		sum = 0; // sum 초기화
		score = 0; // 점수 증가량 초기화
		
	}
	return 0;
}