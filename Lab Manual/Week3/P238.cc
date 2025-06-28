#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size(),1);
        int prod=1;
        for(int i=0;i<nums.size();i++){
            pre[i]*=prod;
            prod*=nums[i];
        }
        prod=1;
        for(int i=nums.size()-1;i>=0;i--){
            pre[i]*=prod;
            prod*=nums[i];
        }
        return pre;
    }
};