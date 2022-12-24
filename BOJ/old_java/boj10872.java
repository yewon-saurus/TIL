package BOJ.old_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class boj10872 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int n = Integer.parseInt(br.readLine());

        n = facto(n);

        bw.write(String.valueOf(n));
        bw.flush();
    }

    public static int facto(int n) {
        int result;
        if (n == 0) {
            result = 1;
        } else if (n == 1) {
            result = 1;
        } else {
            result = n * facto(n - 1);
        }
        return result;
    }
}
