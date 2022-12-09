package BOJ;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class boj2908 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        StringBuffer a = new StringBuffer(st.nextToken());
        int reversA = Integer.parseInt(a.reverse().toString());

        StringBuffer b = new StringBuffer(st.nextToken());
        int reversB = Integer.parseInt(b.reverse().toString());

        if (reversA > reversB) {
            bw.write(String.valueOf(reversA));
        } else {
            bw.write(String.valueOf(reversB));
        }

        bw.flush();
    }
}
