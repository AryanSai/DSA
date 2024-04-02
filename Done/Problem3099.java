package Done;
// 3099. Harshad Number (Easy)
// An integer divisible by the sum of its digits is said to be a Harshad number. You are given an integer x.
// Return the sum of the digits of x if x is a Harshad number, otherwise, return -1.
public class Problem3099 {
    public static int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0, dummy = x;

        while (dummy > 0) {
            sum += (dummy % 10);
            dummy /= 10;
        }
        if (x % sum == 0)
            return sum;
        return -1;
    }

    public static void main(String[] args) {
        System.out.println(sumOfTheDigitsOfHarshadNumber(0));
    }
}
