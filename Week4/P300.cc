#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) 
            for (int j = 0; j < i; j++) 
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], 1 + dp[j]);
        return *max_element(dp.begin(), dp.end());
    }
};