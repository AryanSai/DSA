#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    // TC: O(N) SC: O(N)
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp;
        int temp = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            temp = target - nums[i];
            if (mp.find(temp) != mp.end())
                return vector<int>{mp[temp], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};
int main()
{
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};
    vector<int> sol = solution.twoSum(nums, 9);
    cout << sol[0] << " " << sol[1];
}