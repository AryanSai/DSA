#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void helper(vector<string>& sol, string& s, int n, int open, int close) {
        if (s.size() == n) {
            sol.push_back(s);
            return;
        }

        if (open < n / 2) {
            s.push_back('(');
            helper(sol, s, n, open + 1, close);
            s.pop_back();
        }
        if (open > close) {
            s.push_back(')');
            helper(sol, s, n, open, close + 1);
            s.pop_back();
        }
    }
    vector<string> sol;
    vector<string> generateParenthesis(int n) {
        string s;
        helper(sol, s, 2 * n, 0, 0);
        return sol;
    }
};