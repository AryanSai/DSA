package Done;
import java.util.Arrays;

class Problemm198 {
    static int rob(int[] nums) {
        if (nums.length == 1) {
            return nums[0];
        }
        int[] sums = new int[nums.length];
        sums[0] = nums[0];
        sums[1] = nums[1];
        int max = 0;
        for (int i = 2; i < nums.length; i++) {
            max = 0;
            for (int j = i - 2; j >= 0; j--) {
                if (nums[i] + sums[j] > max) {
                    sums[i] = nums[i] + sums[j];
                    max = sums[i];
                }
            }
        }
        Arrays.sort(sums);
        return sums[sums.length - 1];
    }

    public static void main(String[] args) {
        int[] nums = { 2, 1, 1, 2 };
        System.out.println(rob(nums));
    }
}