package Done;
public class P1894 {
    static int chalkReplacer(int[] chalk, int k) {
        long sum = 0;
        for (int i = 0; i < chalk.length; i++) {
            sum += chalk[i];
        }
        k = (int) (k % sum);
        for (int i = 0; i < chalk.length; i++) {
            if (chalk[i] <= k)
                k -= chalk[i];
            else
                return i;
        }
        return 0;
    }

    public static void main(String[] args) {
        int[] chalk = { 3, 4, 1, 2 };
        System.out.println(chalkReplacer(chalk, 25));
    }
}
