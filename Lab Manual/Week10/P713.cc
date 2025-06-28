#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0, l = 0, prod = 1;
        for (int u = 0; u < nums.size(); u++) {
            prod *= nums[u];
            while (l <= u && prod >= k){
                prod /= nums[l++];
            }
            count += u - l + 1;
        }
        return count;
    }
};