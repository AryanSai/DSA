#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //TC: O(nLogn) SC: O(1)
    int search(vector<int>& nums, int target) {
        int l=0,u=nums.size()-1,mid;
        while(l<=u){
            mid=l+(u-l)/2;
            if(nums[mid]==target)
                return mid;
            if(nums[mid]<target)
                l=mid+1;
            else
                u=mid-1;
        }
        return -1;
    }
};