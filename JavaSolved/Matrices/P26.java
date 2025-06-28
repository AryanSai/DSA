package Done.Matrices;

import java.util.Arrays;

class P26 {
    static int removeDuplicates(int[] nums) {
        int count = 1, done = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[done] != nums[i]) {
                nums[++done] = nums[i];
                count++;
            }
        }
        System.out.println(Arrays.toString(nums));
        return count;
    }

    public static void main(String[] args) {
        int[] nums = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
        System.out.println(removeDuplicates(nums));
    }
}