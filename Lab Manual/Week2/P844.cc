#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    //TC: O(N) SC: O(1)
    bool backspaceCompare(string s, string t) {
        for(int i=0;i<s.size();){
            if(s[i]=='#' && i==0){
                s.erase(i,1);
            }
            else if (s[i]=='#'){
                s.erase(--i,2);
            }else{
                i++;
            }
        }
        for(int i=0;i<t.size();){
            if(t[i]=='#' && i==0){
                t.erase(i,1);
            }
            else if (t[i]=='#'){
                t.erase(--i,2);
                continue;
            }else{
                i++;
            }
        } 
        return s==t;
    }
};