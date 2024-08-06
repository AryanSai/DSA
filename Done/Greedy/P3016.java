package Done.Greedy;
import java.util.Arrays;

class P3016 {
    static int minimumPushes(String word) {
        int[] alpha = new int[26];
        for (char c : word.toCharArray())
            alpha[c - 'a']++;
        Arrays.sort(alpha);
        // System.out.println(Arrays.toString(alpha));
        int div = 1, count = 0;
        for (int i = alpha.length - 1, j = 0; i >= 0 && alpha[i] != 0;) {
            count += (alpha[i] * div);
            i--;
            j++;
            if (j == 8) {
                j = 0;
                div++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        System.out.println(minimumPushes("avghdcyinjmbopwtrfslzkuxeq"));
    }
}