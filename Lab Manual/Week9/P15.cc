#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> sol;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue; 
            int l = i + 1, u = nums.size() - 1;
            while (l < u) {
                int curr = nums[i] + nums[l] + nums[u]; 
                if (curr == 0) {
                    sol.push_back({nums[i], nums[l], nums[u]});
                    
                    while (l < u && nums[l] == nums[l + 1])
                        l++;
                    while (l < u && nums[u] == nums[u - 1])
                        u--;
                    
                    l++;
                    u--;
                } else if (curr < 0)
                    l++; 
                else 
                    u--; 
            }
        }
        return sol;
    }
};
