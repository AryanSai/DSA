package Algorithmica.BinarySearch;

class RightMostIndex {

    //TC: O(log n), SC: O(1)
    //ceiling has to be done here coz we are interested in the upper limit
    //and (l+u)/2 floors the value but we want the ceil 
    static int search(int[] nums, int target) {
        int mid, l = 0, u = nums.length - 1;
        while (l < u) {
            mid = (int) Math.ceil((l + u) / 2.0);
            if (nums[mid] == target) {
                l = mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                u = mid - 1;
            }
        }
        if (target == nums[u]) {
            return u;
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 2, 2, 4, 4, 6, 8};
        System.out.println(search(nums, 2));
    }
}
