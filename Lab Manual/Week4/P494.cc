#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums, 0, 0, target);
    }

private:
    int helper(vector<int>& nums, int index, int sum, int target) {
        if (index == nums.size()) {
            return sum == target ? 1 : 0;
        }
        int add = helper(nums, index + 1, sum + nums[index], target);
        int subtract = helper(nums, index + 1, sum - nums[index], target);
        return add + subtract;
    }
};
