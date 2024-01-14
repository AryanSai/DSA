// Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
class Problem258 {
    static int addDigits(int num) {
        int sum = 0, rem = 0;
        while (num > 0) {
            rem = num % 10;
            sum += rem;
            num /= 10;
        }
        if (sum >= 10) {
            num = sum;
            return addDigits(num);
        }
        return sum;
    }

    public static void main(String[] args) {
        int num = 9;
        int bool = addDigits(num);

        System.out.println(bool);
    }
}