package Algorithmica;

import java.util.Arrays;
import java.util.Random;

public class CountZeroesLeft {

    //TC: O(log n) SC:O(1)
    //we want to converge to the right, hence should use ceil
    static int countZeroes(int[] nums) {
        if (nums.length == 0 || nums[0] != 0) {
            return 0;
        }
        int l = 0, u = nums.length - 1, mid;
        while (l < u) { //when equal would lead to infinite loop
            mid = (int) Math.ceil((l + u) / 2.0);
            if (nums[mid] == 0) {
                l = mid;
            } else {
                u = mid - 1;
            }
        }
        return l + 1; //coz of ceiling
    }

    public static void main(String[] args) {
        int n = 10;
        Random r = new Random();
        int rand = r.nextInt(n);
        int[] nums = new int[n]; //initialised with zeroes
        for (int i = rand; i < n; i++) {
            nums[i] = r.nextInt(n) + 1;//+1 for non zero
        }
        System.out.println(Arrays.toString(nums));
        System.out.println(countZeroes(nums));
    }
}
