#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, l = 0, mini = INT_MAX;
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (sum >= target) {
                mini = min(mini, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        return mini == INT_MAX ? 0 : mini;
    }
};