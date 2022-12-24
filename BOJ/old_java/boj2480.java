package BOJ.old_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj2480 {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] arr = new int[3];
        for (int i = 0; i < arr.length; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        int result;

        if (arr[0] == arr[1] && arr[1] == arr[2]) {
            result = 10000 + arr[0] * 1000;
        } else if (arr[0] == arr[1] || arr[1] == arr[2] || arr[0] == arr[2]) {
            if (arr[0] == arr[1] || arr[0] == arr[2]) {
                result = 1000 + arr[0] * 100;
            } else {
                result = 1000 + arr[1] * 100;
            }
        } else {
            Arrays.sort(arr);
            result = arr[2] * 100;
        }

        bw.write(String.valueOf(result));
        bw.flush();
    }
}
