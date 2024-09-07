#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> sol;  
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;  
        vector<bool> check(nums.size());
        sort(nums.begin(),nums.end());
        backtrack(temp, nums, check);
        return sol;
    }
 
private:
    void backtrack(vector<int>& temp, vector<int> nums, vector<bool>& check) {
        if (temp.size() == nums.size() && find(sol.begin(), sol.end(), temp)==sol.end()) {
            sol.push_back(temp);  
            return;
        }
        for (int i=0;i<nums.size();i++) {
            if (check[i]==true)
                continue; 
            // add the element
            check[i]=true;
            temp.push_back(nums[i]);
            // go back
            backtrack(temp, nums, check);
            // remove the last element
            check[i]=false;
            temp.pop_back();
        }
    }
};