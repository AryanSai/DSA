#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> sol;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        subs(nums, temp, 0);
        return sol;
    }

private:
    void subs(vector<int> nums, vector<int>& temp, int i) {
        if (i == nums.size() &&
            find(sol.begin(), sol.end(), temp) == sol.end()) {
            sol.push_back(temp);
            return;
        }
        if (i < nums.size()) {
            // include
            temp.push_back(nums[i]);
            subs(nums, temp, i + 1);
            // exclude
            temp.pop_back();
            subs(nums, temp, i + 1);
            return;
        }
    }
};