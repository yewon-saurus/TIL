package BOJ.old_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class boj10994 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int I = Integer.parseInt(br.readLine());
		int n = 4 * I - 3; // 격자 크기
		char[][] array = new char[n][n];
		int idx = 0;

		for (int k = 1; k <= I; k++) { // n번 사각형 그리기
			for (int i = idx; i < n - idx; i++) {
				array[idx][i] = '*'; // 사각형 맨 윗줄 그리기
				array[n - idx - 1][i] = '*'; // 맨 아랫줄 그리기
				array[i][idx] = '*'; // 사각형 맨 왼쪽줄 그리기
				array[i][n - idx - 1] = '*'; // 사각형 맨 오른쪽줄 그리기
			}
			idx += 2; // 점점 작은 정사각형을 안쪽에 그려가기 위한 값 변경
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (array[i][j] != '*') {
					bw.write(' ');
				} else {
					bw.write('*');
				}
			}
			bw.write("\n");
		}
		bw.flush();
	}
}
