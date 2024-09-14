#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> sol;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        backtrack(temp, candidates, target, 0);
        return sol;
    }

private:
    void backtrack(vector<int>& temp, vector<int>& candidates, int target, int start) {
        if (target == 0) {
            sol.push_back(temp);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) 
                continue;

            if (candidates[i] > target) 
                break;

            temp.push_back(candidates[i]);
            backtrack(temp, candidates, target-candidates[i], i + 1);
            temp.pop_back();
        }
        return;
    }
};