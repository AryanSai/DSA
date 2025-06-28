#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> sol;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        subs(nums, temp, 0);
        return sol;
    }
private:
    void subs(vector<int> nums, vector<int> temp, int i){
        if(i==nums.size()){
            sol.push_back(temp);
            return;
        }
        //include
        temp.push_back(nums[i]);
        subs(nums,temp,i+1);
        //exclude
        temp.pop_back();
        subs(nums,temp,i+1);
        return;
    }
};