#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for (const vector<int>& pt : points) {
            int dis = pt[0] * pt[0] + pt[1] * pt[1];
            pq.push({dis, pt});
            if (pq.size() > k)
                pq.pop();
        }
        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};