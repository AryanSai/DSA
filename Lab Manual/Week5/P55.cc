#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> check(nums.size(), 0);
        int n = nums.size() - 1;
        check[n]=1;
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] >= n - i){
                check[i] = 1;
            }
            else
                for (int j = i + 1; j <= n; j++) {
                    if (nums[i] >= j - i && check[j])
                        check[i] = 1;
                }
        }
        return check[0];
    }
};