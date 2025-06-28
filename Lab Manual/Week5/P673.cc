#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1), count(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) 
            for (int j = 0; j < i; j++) 
                if(nums[j]<nums[i])
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    } else if (dp[i] == dp[j] + 1) 
                        count[i] += count[j];
        //Count how many sequences have the longest length
        int countt = 0;
        int maxi = *max_element(dp.begin(), dp.end());
        for (int i = 0; i < nums.size(); i++) 
            if (dp[i] == maxi) 
                countt += count[i];
        return countt;
    }
};