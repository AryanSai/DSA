#include <iostream>
#include <vector>

using namespace std;

//same as coin change
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int count = 0;
        vector<int> dp(target + 1, 0);
        dp[0]=1;
        for (int i = 1; i <= target; i++) {
            long long temp=0;
            for (int j = 0; j < nums.size(); j++) {
                if (i - nums[j] >= 0) {
                    temp += dp[i - nums[j]];
                }
            }
            dp[i]=temp;
        }
        return dp[target];
    }
};