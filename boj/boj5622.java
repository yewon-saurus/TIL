package BOJ;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class boj5622 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        String temp;
        int howMuch = 0;

        temp = br.readLine();

        for (int i = 0; i < temp.length(); i++) {
            if (temp.charAt(i) == 'A' || temp.charAt(i) == 'B' || temp.charAt(i) == 'C') {
                howMuch += 3;
            } else if (temp.charAt(i) == 'D' || temp.charAt(i) == 'E' || temp.charAt(i) == 'F') {
                howMuch += 4;
            } else if (temp.charAt(i) == 'G' || temp.charAt(i) == 'H' || temp.charAt(i) == 'I') {
                howMuch += 5;
            } else if (temp.charAt(i) == 'J' || temp.charAt(i) == 'K' || temp.charAt(i) == 'L') {
                howMuch += 6;
            } else if (temp.charAt(i) == 'M' || temp.charAt(i) == 'N' || temp.charAt(i) == 'O') {
                howMuch += 7;
            } else if (temp.charAt(i) == 'P' || temp.charAt(i) == 'Q' || temp.charAt(i) == 'R'
                    || temp.charAt(i) == 'S') {
                howMuch += 8;
            } else if (temp.charAt(i) == 'T' || temp.charAt(i) == 'U' || temp.charAt(i) == 'V') {
                howMuch += 9;
            } else {
                howMuch += 10;
            }
        }
        bw.write(String.valueOf(howMuch));
        bw.flush();
    }
}
