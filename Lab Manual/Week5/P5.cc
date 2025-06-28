#include <iostream>
using namespace std;

class Solution {
public:
    int len = 0;
    string sol;
    void rev(string s, int l, int u) {
        while (l >= 0 && u < s.size() && s[l] == s[u]) {
            if (u - l + 1 > len) {
                len = u - l + 1;
                sol = s.substr(l, len);
            }
            l--;
            u++;
        }
    }
    string longestPalindrome(string s) {
        if (s.size() == 1)
            return s;
        for (int i=0; i < s.size(); i++) {
            rev(s, i, i);     // odd
            rev(s, i, i + 1); // even
        }
        return sol;
    }
};