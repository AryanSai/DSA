package Done;
// 349. Intersection of Two Arrays(Easy)
// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the
// result must be unique and you may return the result in any order.
// Example 1:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
// Example 2:
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Explanation: [4,9] is also accepted.
// Constraints:
// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 1000

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Problem349 {
    static int[] intersection(int[] nums1, int[] nums2) {
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
        int[] result = new int[inter.size()];
        for (int i = 0; i < inter.size(); i++) {
            result[i] = inter.get(i);
        }
        return result;
    }

    public static void main(String[] args) {
        int[] nums1 = { 4,9,5 }, nums2 = { 9,4,9,8,4 };
        int[] result = intersection(nums1, nums2);
        for (int num : result) {
            System.out.println(num);
        }
    }
}
