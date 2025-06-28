#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = nums[0], sum = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            sum = max(sum + nums[i], nums[i]);
            maxi = max(sum, maxi);
        }
        return maxi;
    }
};