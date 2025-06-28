#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> sol;
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        backtrack(temp, n, k, 1);
        return sol;
    }
    void backtrack(vector<int>& temp, int n, int k, int start) {
        if (temp.size() == k) {
            sol.push_back(temp);
            return;
        }

        for (int i = start; i <= n; i++) {
            temp.push_back(i);
            backtrack(temp,n,k,i+1);
            temp.pop_back();
        }
        return;
    }
};