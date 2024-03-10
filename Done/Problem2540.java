package Done;
// 2540. Minimum Common Value(Easy)
// Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer
// common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.
// Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence
// of that integer.
// Example 1:
// Input: nums1 = [1,2,3], nums2 = [2,4]
// Output: 2
// Explanation: The smallest element common to both arrays is 2, so we return 2.
// Example 2:
// Input: nums1 = [1,2,3,6], nums2 = [2,3,4,5]
// Output: 2
// Explanation: There are two common elements in the array 2 and 3 out of which 2 is the smallest, so 2 is
// returned.
// Constraints:
// 1 <= nums1.length, nums2.length <= 105
// 1 <= nums1[i], nums2[j] <= 109
// Both nums1 and nums2 are sorted in non-decreasing order.

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class Problem2540 {
    static int getCommon(int[] nums1, int[] nums2) {
        Set<Integer> ht = new HashSet<>();
        List<Integer> inter = new ArrayList<>();
        for (int num : nums1) {
            ht.add(num);
        }
        for (int num : nums2) {
            if (ht.contains(num)) {
                inter.add(num);
                ht.remove(num);
            }
        }
        Collections.sort(inter);
        if (!inter.isEmpty()) {
            int result = inter.get(0);
            return result;
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] nums1 = { 1, 2, 3, 6 }, nums2 = { 2, 3, 4, 5 };
        System.out.println(getCommon(nums1, nums2));
    }
}