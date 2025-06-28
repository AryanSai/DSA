#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, u = nums.size() - 1, mid=0;
        while (l < u) {
            mid = (l + u) / 2;
            if (nums[mid] < nums[nums.size() - 1])
                u = mid;
            else 
                l = mid+1; //since the smallest is on the right, this is useless
        }
        return nums[l];
    }
};