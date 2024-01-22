public class Problem645 {
    static int[] findErrorNums(int[] nums) {
        int[] count = new int[nums.length];
        for (int i = 0; i <= nums.length - 1; i++) {
            count[nums[i] - 1] += 1;
        }
        int duplicate = 0;
        int missing = 0;

        for (int i = 0; i < count.length; i++) {
            if (count[i] == 2) {
                duplicate = i + 1;
            } else if (count[i] == 0) {
                missing = i + 1;
            }
        }
        return new int[] { duplicate, missing };
    }

    public static void main(String[] args) {
        int nums[] = { 1, 3,3 };
        int sol[] = findErrorNums(nums);
        System.out.println(sol[0]);
        System.out.println(sol[1]);
    }
}
