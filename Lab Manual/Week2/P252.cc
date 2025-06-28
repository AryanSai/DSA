#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canAttendMeetings(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        for (int i = 1; i < intervals.size(); i++)
            if (intervals[i - 1][1] > intervals[i][0])
                return false;
        return true;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> intervals = {
        {7, 10},
        {2, 4}};
    cout << "Answer: " << solution.canAttendMeetings(intervals) << endl;
}
