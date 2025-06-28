#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, u = nums.size() - 1, i = 0;
        for (int i = 0; i <= u;) {
            if (nums[i] == 0) {
                swap(nums[i], nums[l]);
                l++;
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[u]);
                u--;
            } else {
                i++;
            }
        }
    }
};