package boj;

import java.util.Scanner;

public class boj2525 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int m = sc.nextInt();
        int s = sc.nextInt();
        int howMuch = sc.nextInt();

        s += howMuch;

        if (s >= 60) {
            m += s / 60;
            s -= s / 60 * 60;
        }
        if (m >= 24) {
            m -= 24;
        }

        System.out.println(m + " " + s);
    }
}
