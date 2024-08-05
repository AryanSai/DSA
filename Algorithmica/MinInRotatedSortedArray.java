package Algorithmica;

public class MinInRotatedSortedArray {

    static int mini(int[] nums) {
        int l = 0, u = nums.length - 1, mid;
        while (l < u) {
            mid = (l + u) / 2;
            if (nums[mid] < nums[nums.length - 1]) {
                u = mid;
            } else {
                l = mid+1; //since the smallest is on the right, this is useless
            }
        }
        return l;
    }

    public static void main(String[] args) {
        int[] nums = {7, 8, 9, 1, 2, 3, 4, 5, 6};
        System.out.println(mini(nums));
    }
}
