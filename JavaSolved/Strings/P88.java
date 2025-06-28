package Algorithmica.Assignnments;

import java.util.Arrays;

class P88 {
    static void merge(int[] nums1, int m, int[] nums2, int n) {
        int i = m - 1, j = n - 1, last = nums1.length - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[last] = nums1[i];
                i--;
            } else {
                nums1[last] = nums2[j];
                j--;
            }
            last--;
        }
    }

    public static void main(String[] args) {
        int[] nums1 = { 0 }, nums2 = { 1 };
        merge(nums1, 0, nums2, 1);
        System.out.println(Arrays.toString(nums1));
    }
}