#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> sol;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        backtrack(sol, temp, k, n, 0, 1);
        return sol;
    }
    void backtrack(vector<vector<int>>& sol, vector<int>& temp, int k, int n,
                   int j, int start) {
        if (n == 0 && j == k) {
            sol.push_back(temp);
            return;
        }
        for (int i = start; i <= 9; i++) {
            if (i > n)
                break;
            if (find(temp.begin(), temp.end(), i) == temp.end()) {
                temp.push_back(i);
                backtrack(sol, temp, k, n - i, j + 1, i + 1);
                temp.pop_back();
            }
        }
    }
};