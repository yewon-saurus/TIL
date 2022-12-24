package BOJ.old_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class boj2522 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        for (int i = 1; i <= 2 * n - 1; i++) {
            if (i <= n) {
                for (int j = 1; j <= n - i; j++) {
                    bw.write(" ");
                }
                for (int j = 1; j <= i; j++) {
                    bw.write("*");
                }
            } else {
                for (int j = 1; j <= i % n; j++) {
                    bw.write(" ");
                }
                for (int j = 1; j <= n - (i % n); j++) {
                    bw.write("*");
                }
            }
            bw.write("\n");
        }
        bw.flush();
    }
}
