package Done;
class Problem896 {
    static boolean isMonotonic(int[] nums) {
        int inc = 0, dec = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i - 1] <= nums[i]) {
                inc++;
            }
            if (nums[i - 1] >= nums[i]) {
                dec++;
            }
        }
        return (inc == nums.length - 1) || (dec == nums.length - 1);
    }

    public static void main(String[] args) {
        int[] nums = { 1, 1 };
        System.out.println(isMonotonic(nums));
    }
}