#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0, maxi = 0;
        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) != mp.end() && mp[s[i]] >= l) 
                l = mp[s[i]] + 1;
            mp[s[i]] = i;
            maxi = max(maxi, i - l + 1);
        }
        return maxi;
    }
};