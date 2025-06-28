#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i:nums){
            if(mp.find(i)!=mp.end()){
                return true;
            }
            mp.insert({i,1});
        }
        return false;
    }
};