package BOJ.old_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class boj10992 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        for (int i = 1; i <= n; i++) {
            if (i == n) {
                for (int j = 1; j <= 2 * n - 1; j++) {
                    bw.write("*");
                }
            } else if (i == 1) {
                for (int j = 1; j <= n - i; j++) {
                    bw.write(" ");
                }
                bw.write("*");
            } else {
                for (int j = 1; j <= n - i; j++) {
                    bw.write(" ");
                }
                bw.write("*");
                for (int j = 1; j <= 2 * (i - 1) - 1; j++) {
                    bw.write(" ");
                }
                bw.write("*");
            }
            bw.write("\n");
        }
        bw.flush();
    }
}
