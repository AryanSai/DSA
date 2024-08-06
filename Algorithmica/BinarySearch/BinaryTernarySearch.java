package Algorithmica.BinarySearch;
// import java.util.Arrays;

class BinaryTernarySearch {
    static int[] array(int n) {
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = i;
        }
        // System.out.println(Arrays.toString(arr));
        return arr;
    }

    // TC: O(log2n); SC: O(1)
    static boolean binsearch(int[] nums, int x) {
        int mid, l = 0, u = nums.length - 1;
        if (x < nums[l] || x > nums[u]) {
            return false;
        }
        while (l <= u) {
            mid = (l + u) / 2;
            if (nums[mid] == x) {
                return true;
            } else if (x > nums[mid]) {
                l = mid + 1;
            } else {
                u = mid - 1;
            }
        }
        return false;
    }

    // TC: O(log3n); SC: O(1)
    static boolean ternarysearch(int[] nums, int x) {
        int size, m1, m2, l = 0, u = nums.length - 1;
        while (l <= u) {
            size = (u - l + 1) / 3;
            m1 = l + size;
            m2 = u - size;
            if (x == nums[m1] || x == nums[m2]) {
                return true;
            }
            if (x < nums[m1]) {
                u = m1 - 1;
            } else if (x > nums[m2]) {
                l = m2 + 1;
            } else {
                l = m1 + 1;
                u = m2 - 1;
            }
        }
        return false;
    }

    //Random mid point approach
    //in worst case, it will be O(n) only
    //hence useless
    
    public static void main(String[] args) {
        int[] nums = array(100000000);
        System.out.println(binsearch(nums, 3));
        System.out.println(ternarysearch(nums, 3));
    }
}