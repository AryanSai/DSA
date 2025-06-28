#include <iostream>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        auto check = [&](int l, int u){
            while(l>=0 && u<=s.size() && s[l]==s[u]){
                count++;
                l--;
                u++;
            }
        };
        for(int i=0;i<s.size();i++){
            check(i,i);
            check(i,i+1);
        }
        return count;
    }
};