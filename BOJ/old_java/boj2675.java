package BOJ.old_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class boj2675 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;

        int n = Integer.parseInt(br.readLine());
        int r;
        String s;
        String[] temp;

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());

            r = Integer.parseInt(st.nextToken());
            s = st.nextToken();

            temp = s.split("");
            for (int j = 0; j < s.length(); j++) {
                for (int k = 0; k < r; k++) {
                    bw.write(String.valueOf(temp[j]));
                }
            }
            bw.newLine();
        }
        bw.flush();
    }
}
