#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> sol;  
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;  
        backtrack(sol, temp, nums);
        return sol;
    }

private:
    void backtrack(vector<vector<int>>& sol, vector<int> temp, vector<int> nums) {
        if (temp.size() == nums.size()) {
            sol.push_back(temp);  
            return;
        }
        for (int n : nums) {
            if (find(temp.begin(), temp.end(), n) != temp.end())
                continue; 
            // add the element
            temp.push_back(n);
            // go back
            backtrack(sol, temp, nums);
            // remove the last element
            temp.pop_back();
        }
    }
};
