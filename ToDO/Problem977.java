package ToDO;
// 977. Squares of a Sorted Array(Easy)
// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number
// sorted in non-decreasing order.
// Example 1:
// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].
// Example 2:
// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]

public class Problem977 {
    static int[] sortedSquares(int[] nums) {
        int l = 0, u = nums.length - 1;
        while (l <= u) {
            for (int num : nums) {
                System.out.print(num + " ");
            }
            System.out.println();
        }
        return nums;
    }

    public static void main(String[] args) {
        int[] nums = { -5,-3,-2,-1};
        int[] sol = sortedSquares(nums);
        for (int num : sol) {
            System.out.println(num);
        }
    }
}
