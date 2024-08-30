#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l=0,u=letters.size()-1,mid;
        if(target < letters[l] || target >= letters[u]){
            return letters[0];
        }
        while(l<u){
            mid=(l+u)/2;
            if(letters[mid]>target)
                u=mid;
            else
                l=mid+1;
        }
        return letters[u];
    }
};