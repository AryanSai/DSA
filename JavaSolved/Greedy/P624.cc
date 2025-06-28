#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int mini = arrays[0][0];
        int maxi = arrays[0].back();
        int diff = 0;

        for (int i = 1; i < arrays.size(); i++)
        {
            diff = max(diff, max(abs(arrays[i].back() - mini), abs(maxi - arrays[i][0])));
            maxi = max(maxi, arrays[i].back());
            mini = min(mini, arrays[i][0]);
        }
        return diff;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> arrays = {
        {1, 2, 3},
        {4, 5},
        {1, 2, 3}};

    cout << sol.maxDistance(arrays) << endl;

    return 0;
}
