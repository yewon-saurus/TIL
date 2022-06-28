package boj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class boj2525 {
    public void sol() throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out)); // 앞으로 br, bw는 세트로 생각하겠어요
        StringTokenizer st = new StringTokenizer(br.readLine());

        int m = Integer.parseInt(st.nextToken());
        int s = Integer.parseInt(st.nextToken());

        // 변수 한 개는 StringTokenizer가 아니라!! 기본 입력을 사용해요
        int howMuch = Integer.parseInt(br.readLine());

        s += howMuch;

        if (s >= 60) {
            m += s / 60;
            s -= s / 60 * 60;
        }
        if (m >= 24) {
            m -= 24;
        }

        // System.out.println(m + " " + s); -> 느립니다.. bw로 대체 할거예요
        // bw.write(String.valueOf(m + " " + s)); -> String에 대한 '+' 연산 자체가 느리다.. 빠른 출력을 쓰는 의미 퇴색
        bw.write(String.valueOf(m));
        bw.write(String.valueOf(" "));
        bw.write(String.valueOf(s));
        bw.flush();
    }

    public static void main(String[] args) throws Exception {
        new boj2525().sol();
    }
}
