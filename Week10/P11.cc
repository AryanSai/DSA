#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, u = height.size() - 1, maxi = INT_MIN;
        while (l <= u) {
            maxi = max(maxi, min(height[l], height[u]) * (u - l));
            if (height[l] < height[u])
                l++;
            else
                u--;
        }
        return maxi;
    }
};