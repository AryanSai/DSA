#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0,i=0;
        double avg=0;
        for(;i<k;i++)
            sum+=nums[i];
        avg = static_cast<double>(sum)/k;
        for(;i<nums.size();i++){
            sum+=(nums[i]-nums[i-k]);
            avg=max(avg, static_cast<double>(sum)/k);
        }
        return avg;
    }
};