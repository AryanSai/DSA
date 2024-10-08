#include <iostream>
#include <vector>

using namespace std;

//TC: O(nlogn); SC:O(1)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        for (int i = 0; i < intervals.size() - 1; i++) {
            if (intervals[i + 1][0] >= intervals[i][0] &&
                intervals[i + 1][0] <= intervals[i][1]){
                    intervals[i][1] = max(intervals[i][1],intervals[i + 1][1]);
                    intervals.erase(intervals.begin() + i+1);
                    i--;
                }
        }
        return intervals;
    }
};