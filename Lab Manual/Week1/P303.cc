#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class NumArray {
public:
    int psum[10000];  
    
    NumArray(vector<int>& nums) {
        psum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++) 
            psum[i] = psum[i - 1] + nums[i];  
    }
    
    int sumRange(int left, int right) {
        if (left == 0) 
            return psum[right];  
        return psum[right] - psum[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */