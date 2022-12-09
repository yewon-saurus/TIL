package BOJ;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class boj13015 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());
        int i, j;

        for (i = 1; i <= 2 * n - 1; i++) { // 첫 번째 줄, 두 번째 줄 ...
            if (i == 1 || i == (n + (n - 1))) { // 첫 번째 줄과 마지막 줄, 즉 천장과 바닥
                for (j = 1; j <= n; j++) {
                    bw.write("*");
                }
                for (j = 1; j <= (n - 1) + (n - 2); j++) { // 테두리 바깥 공백
                    bw.write(" ");
                }
                for (j = 1; j <= n; j++) {
                    bw.write("*");
                }
            } else { // 그 외, 기둥을 만드는 부분
                if (i < n) {
                    for (j = 1; j <= i - 1; j++) {
                        bw.write(" ");
                    }
                    bw.write("*");
                    for (j = 1; j <= n - 2; j++) {
                        bw.write(" ");
                    }
                    bw.write("*");
                    for (j = 1; j <= (n - 1) + (n - 2) - 2 * (i - 1); j++) { // 테두리 바깥 공백
                        bw.write(" ");
                    }
                    bw.write("*");
                    for (j = 1; j <= n - 2; j++) {
                        bw.write(" ");
                    }
                    bw.write("*");
                }
                if (i > n) {
                    for (j = 1; j <= n - (i % n) - 1; j++) {
                        bw.write(" ");
                    }
                    bw.write("*");
                    for (j = 1; j <= n - 2; j++) {
                        bw.write(" ");
                    }
                    bw.write("*");
                    for (j = 1; j <= 2 * (i % n) - 1; j++) { // 테두리 바깥 공백
                        bw.write(" ");
                    }
                    bw.write("*");
                    for (j = 1; j <= n - 2; j++) {
                        bw.write(" ");
                    }
                    bw.write("*");
                } else if (i == n) {
                    for (j = 1; j <= i - 1; j++) {
                        bw.write(" ");
                    }
                    bw.write("*");
                    for (j = 1; j <= n - 2; j++) {
                        bw.write(" ");
                    }
                    bw.write("*");
                    for (j = 1; j <= n - 2; j++) {
                        bw.write(" ");
                    }
                    bw.write("*");
                }
            }
            bw.write("\n");
        }

        bw.flush();
    }
}
