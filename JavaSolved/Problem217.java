package Done;
// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
// Example 1:
// Input: nums = [1,2,3,1]
// Output: true
// Example 2:
// Input: nums = [1,2,3,4]
// Output: false
// Example 3:
// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true

import java.util.Hashtable;

public class Problem217 {

    static boolean containsDuplicate(int[] nums) {
        Hashtable<Integer, Integer> ht = new Hashtable<>();
        for (int num : nums) {
            if (ht.containsKey(num)) {
                return true;
            }
            ht.put(num, 1);
        }
        return false;
    }

    public static void main(String[] args) {
        int[] nums = { 1 };
        System.out.println(containsDuplicate(nums));
    }
}
