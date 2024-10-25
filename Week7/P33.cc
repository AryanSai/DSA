#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, u = nums.size() - 1;
        while (l <= u) {
            int mid = l + (u - l) / 2;
            if (nums[mid] == target)
                return mid;
            // if the left part is sorted
            if (nums[l] <= nums[mid]) {
                // target is within the left sorted part
                if (target >= nums[l] && target < nums[mid])
                    u = mid - 1;
                else
                    l = mid + 1;
            }
            // right part is sorted
            else {
                // target is within the right sorted part
                if (target > nums[mid] && target <= nums[u])
                    l = mid + 1; 
                else
                    u = mid - 1; 
            }
        }
        return -1;
    }
};