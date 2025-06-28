#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> set(nums.begin(), nums.end());
        int maxx = 0;
        for (int num : nums) {
            if (set.find(num - 1) == set.end()) {
                int curr = num;
                int count = 1;
                while (set.find(curr + 1) != set.end()) {
                    curr++;
                    count++;
                }
                maxx = max(maxx, count);
            }
        }
        return maxx;
    }
};
