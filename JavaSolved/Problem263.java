package Done;
class Problem263 {
    static boolean isUgly(int n) {
        if (n == 0) {
            return false;
        }
        while (n % 5 == 0) {
            n = n / 5;
        }
        while (n % 3 == 0) {
            n = n / 3;
        }
        while (n % 2 == 0) {
            n = n / 2;
        }

        if (n == 1) {
            return true;
        }
        return false;
    }

    public static void main(String[] args) {
        int n = 0;
        boolean bool = isUgly(n);

        System.out.println(bool);
    }
}