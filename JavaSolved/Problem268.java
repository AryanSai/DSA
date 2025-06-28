package Done;
import java.util.Arrays;

class Problem268 {
    static int missingNumber(int[] nums) {
        Arrays.sort(nums);
        int i;
        for (i = 0; i < nums.length; i++) {
            if (i != nums[i]) {
                return i;
            }
        }
        return i;
    }

    public static void main(String[] args) {
        int[] nums = { 0, 1 };

        System.out.println(missingNumber(nums));
    }
}