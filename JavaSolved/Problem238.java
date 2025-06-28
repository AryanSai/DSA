package Done;
// 238. Product of Array Except Self (Medium)
// Given an integer array nums, return an array answer such that answer[i] is equal to the product of all
// the elements of nums except nums[i].
// The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
// You must write an algorithm that runs in O(n) time and without using the division operation.
// Example 1:
// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:
// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

import java.util.Arrays;

class Problem238 {
    static int[] productExceptSelf(int[] nums) {
        int product = 1, count = 0;
        for (int num : nums) {
            if (num != 0) {
                product *= num;
            } else {
                if (count == 1) {
                    product = 0;
                    break;
                }
                count++;
            }
        }
        int[] sol = new int[nums.length];
        if (product == 0) {
            Arrays.fill(sol, 0);
            return sol;
        }
        for (int i = 0; i < sol.length; i++) {
            if (nums[i] == 0) {
                sol[i] = product;
            } else {
                if (count == 1) {
                    sol[i] = 0;
                } else {
                    sol[i] = product / nums[i];
                }
            }
        }
        return sol;
    }

    public static void main(String[] args) {
        int[] nums = { 0, 0 };
        int[] sol = productExceptSelf(nums);
        for (int num : sol) {
            System.out.println(num);
        }
    }
}