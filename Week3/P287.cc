#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0,fast=0;
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(fast!=slow);
        int slow2=0;
        do{
            slow=nums[slow];
            slow2=nums[slow2];
        }while(slow2!=slow);
        return slow;
    }
};