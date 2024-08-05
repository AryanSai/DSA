package Algorithmica;

import java.util.Arrays;
import java.util.Random;

public class CountZeroesRight {

    //TC: O(log n) SC:O(1)
    static int countZeroes(int[] nums) {
        if (nums.length == 0 || nums[nums.length - 1] != 0) {
            return 0;
        }
        int l = 0, u = nums.length - 1, mid;
        while (l < u) { //when equal would lead to infinite loop
            mid = (l + u) / 2;
            if (nums[mid] == 0) {
                u = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums.length - l;
    }

    public static void main(String[] args) {
        int n = 10;
        Random r = new Random();
        int rand = r.nextInt(n);
        int[] nums = new int[n]; //initialised with zeroes
        for (int i = 0; i < rand; i++) {
            nums[i] = r.nextInt(n) + 1;//+1 for non zero
        }
        System.out.println(Arrays.toString(nums));
        System.out.println(countZeroes(nums));
    }
}
