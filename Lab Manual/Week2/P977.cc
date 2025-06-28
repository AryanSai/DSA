#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> sol(nums.size(),0);
        int l=0,u=nums.size()-1,i=nums.size()-1;
        while(l<=u){
            if(abs(nums[l]) < abs(nums[u])){
                sol[i]=nums[u]*nums[u];
                u--;
            }else{
                sol[i]=nums[l]*nums[l];
                l++;
            }
            i--;
        }
        return sol;
    }
};