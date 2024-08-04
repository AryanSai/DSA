package Done.BinSearch;

import java.util.Arrays;


public class P34 {

    static int[] searchRange(int[] nums, int target) {
        int mid, l = 0, u = nums.length - 1;
        int[] sol = {-1, -1};
        while (l < u) {
            mid = (l + u) / 2;
            if (nums[mid] == target) {
                u = mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                u = mid - 1;
            }
        }
        if (target == nums[l]) {
            sol[0] = l;
        }
        l = 0;
        u = nums.length - 1;
        while (l < u) {
            mid = (int) Math.ceil((l + u) / 2.0);
            if (nums[mid] == target) {
                l = mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                u = mid - 1; 
            }
        }
        if (target == nums[u]) {
            sol[1] = u;
        }
        return sol;
    }

    public static void main(String[] args) {
        int[] nums = {};
        System.out.println(Arrays.toString(searchRange(nums, 2)));
    }
}
