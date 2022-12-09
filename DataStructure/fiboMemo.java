package DataStructure;

import java.util.Scanner;

public class fiboMemo {
    public static final int howMuch = 100;
    public static long fibArray[] = new long[howMuch];

    public static long fibonacci(long n) {
        long fibValue = 0;

        if (n == 0)
            return 0; // base case
        else if (n == 1)
            return 1; // base case
        else {
            fibValue = fibonacci(n - 1) + fibonacci(n - 2);
            fibArray[(int) n] = fibValue;
            return fibValue;
        }
    }

    public static void main(String args[]) {
        fibArray[0] = 0;
        fibArray[1] = 1;

        System.out.println("Enter n: ");
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println("F(" + n + ") = " + fibonacci(n));

        sc.close();
    }
}