#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum=0,n=nums.size(),total=(n*(n+1))/2;
        for(int i:nums){
            sum+=i;
        }
        return total-sum;
    }
};