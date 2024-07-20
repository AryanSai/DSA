package Done.TwoPointers;
import java.util.Arrays;

public class P283 {
    static void moveZeroes(int[] nums) {
        int zeroes = nums.length - 1;
        for (int i = nums.length - 1; i >= 0; i--) {
            if (nums[i] == 0) {
                System.out.println(i);
                for (int j = i; j < zeroes; j++) {
                    nums[j] = nums[j + 1];
                }
                nums[zeroes] = 0;
                zeroes--;
            }
        }
    }

    public static void main(String[] args) {
        int[] nums = { 0, 1, 0, 3, 12 };
        moveZeroes(nums);
        System.out.println(Arrays.toString(nums));
    }
}
