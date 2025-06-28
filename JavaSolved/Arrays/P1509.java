package Done.Arrays;

import java.util.Arrays;

public class P1509 {
    static int minDifference(int[] nums) {
        if(nums.length<5) return 0;
        Arrays.sort(nums);
        int min = Integer.MAX_VALUE,l=nums.length;
        min =  Math.min(min, nums[l-1]-nums[3]);
        min =  Math.min(min, nums[l-4]-nums[0]);
        min =  Math.min(min, nums[l-2]-nums[2]);
        min =  Math.min(min, nums[l-3]-nums[1]);
        return min;
    }

    public static void main(String[] args) {
        int[] nums={1,5,0,10,14};
        System.out.println(minDifference(nums));
    }
}
