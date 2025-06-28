#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int sol=0;
        for(int n:nums){
            sol^=n;
        }
        return sol;
    }
};