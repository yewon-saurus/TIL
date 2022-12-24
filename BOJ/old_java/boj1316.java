package BOJ.old_java;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class boj1316 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;

		int n = Integer.parseInt(br.readLine());
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());

			String S = st.nextToken();
			boolean check[] = new boolean[26];
			boolean tmp = true;

			for (int j = 0; j < S.length(); j++) {
				int index = S.charAt(j) - 'a';
				if (check[index]) {
					if (S.charAt(j) != S.charAt(j - 1)) {
						tmp = false;
						break;
					}
				} else {
					check[index] = true;
				}
			}
			if (tmp)
				cnt++;
		}

		bw.write(String.valueOf(cnt));
		bw.flush();
	}
}
