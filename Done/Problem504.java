package Done;
class Problem504 {
    static boolean checkPerfectNumber(int num) {
        int i = 1, sum = 0;
        while (i <= num / 2) {
            if (num % i == 0) {
                sum += i;
            }
            i++;
        }
        return sum == num;
    }

    public static void main(String[] args) {
        int num = 120;
        System.out.println(checkPerfectNumber(num));
    }
}

// public boolean checkPerfectNumber(int num) {
//     int i = num / 2, sum = 1;
//     while (i > 1) {
//         if (num % i == 0) {
//             sum += i;
//         }
//         i = (i + 1) / 2;
//     }
//     return sum == num;
// }