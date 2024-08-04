package Algorithmica;

class LeftMostIndex {

    //TC: O(log n), SC: O(1)
    static int search(int[] nums, int target) {
        int mid, l = 0, u = nums.length - 1;
        while (l < u) {
            mid = (l + u) / 2;
            if (nums[mid] == target) {
                u = mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                u = mid - 1;
            }
        }
        if(target == nums[l]){
            return l;
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] nums = {1, 2, 2, 2};
        System.out.println(search(nums, 2));
    }
}
