#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> sol;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, temp, target, 0);
        return sol;
    }

private:
    void backtrack(vector<int>& candidates, vector<int>& temp, int target, int start) {
        if (target == 0) {
            sol.push_back(temp);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if (candidates[i] > target) 
                break;
            temp.push_back(candidates[i]);
            backtrack(candidates, temp, target - candidates[i], i);
            temp.pop_back(); 
        }
    }
};