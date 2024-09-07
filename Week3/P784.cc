#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> sol;
    vector<string> letterCasePermutation(string s) {
        helper(s, 0);
        return sol;
    }

private:
    void helper( string s, int i) {
        if (i == s.size()) {
            sol.push_back(s);
            return;
        } 
        helper(s, i + 1);
        if (isalpha(s[i])) {
            s[i] ^= 32; // toggle case by XORing with 32
            helper(s, i + 1);
        }
    }
};