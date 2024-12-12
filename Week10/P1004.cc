#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, maxi = INT_MIN;
        for (int u = 0; u < nums.size(); u++) {
            if (nums[u] == 0)
                k--;
            while (k < 0) {
                if (nums[l] == 0)
                    k++;
                l++;
            }
            maxi = max(maxi, u - l + 1);
        }
        return maxi;
    }
};