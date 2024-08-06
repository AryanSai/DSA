package Algorithmica.BinarySearch;
// 2) Ceil: Given a sorted array and a target value, return the index if the target is 
// found. If not,
// return the index of the next immediate higher element in the array. You may assume no
// duplicates in the array.
// Example :
// Input: [1,3,5,6], 4
// Output: 2

class CeilInArray {

    // TC: O(log2n); SC: O(1)
    static int ceil(int[] nums, int x) {
        int l = 0, u = nums.length - 1, mid;
        while (l < u) {
            mid = l + ((u - l) / 2);
            if (x == nums[mid]) {
                return mid;
            }
            if (x > nums[mid]) {
                l = mid + 1;
            } else {
                u = mid;
            }
        }
        return l;
    }

    public static void main(String[] args) {
        int[] nums = {1, 5, 6, 7, 8, 10, 15, 16, 20};
        System.out.println(ceil(nums, 7));
    }
}
