#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // turn all not in the range [1,n] into 0s
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n)
                nums[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]);
            if (val > 0 && val <= n) {
                if (nums[val - 1] > 0)
                    nums[val - 1] = -nums[val - 1];
                else if (nums[val - 1] == 0)
                    nums[val - 1] = -(n + 1);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0)
                return i + 1;
        }
        return n + 1;
    }
};