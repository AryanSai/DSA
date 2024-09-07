#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> sol;
        for(int n:nums){
            nums[abs(n)-1]*=-1;
            if(nums[abs(n)-1]>0){
                sol.push_back(abs(n));
            }
        }
        return sol;
    }
};