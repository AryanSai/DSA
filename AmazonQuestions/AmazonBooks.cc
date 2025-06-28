#include <iostream>
#include <vector>

using namespace std;

vector<int> getStaleSkillCount(
    int numSkills,
    vector<vector<int>> &requestLogs,
    vector<int> &queryTimes,
    int timeWindow)
{
    int m = requestLogs.size();
    int q = queryTimes.size();

    // Sort requestLogs by timestamp
    sort(requestLogs.begin(), requestLogs.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
    });
    // Store queryTimes with their original indices
    vector<pair<int, int>> queries; // {time, index}
    for (int i = 0; i < q; ++i)
    {
        queries.push_back({queryTimes[i], i});
    }
    sort(queries.begin(), queries.end());

    vector<int> ans(q);
    unordered_map<int, int> skillCount; // skillID -> count
    int left = 0, right = 0;

    for (auto &[time, idx] : queries)
    {
        int start = time - timeWindow;
        int end = time;

        // Expand right boundary
        while (right < m && requestLogs[right][1] <= end)
        {
            int skill = requestLogs[right][0];
            skillCount[skill]++;
            right++;
        }

        // Shrink left boundary
        while (left < m && requestLogs[left][1] < start)
        {
            int skill = requestLogs[left][0];
            skillCount[skill]--;
            if (skillCount[skill] == 0)
                skillCount.erase(skill);
            left++;
        }

        ans[idx] = numSkills - skillCount.size(); // skills not seen in this window
    }

    return ans;
}

int main()
{
    // Example 1
    int numSkills = 3;
    vector<vector<int>> requestLogs = {{1, 3}, {2, 6}, {1, 5}};
    vector<int> queryTimes = {10, 11};
    int timeWindow = 5;

    vector<int> result = getStaleSkillCount(numSkills, requestLogs, queryTimes, timeWindow);

    cout << "Output:\n";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    // Example 2
    numSkills = 6;
    requestLogs = {{3, 2}, {4, 3}, {2, 6}, {6, 3}};
    queryTimes = {3, 2, 6};
    timeWindow = 2;

    vector<int> result2 = getStaleSkillCount(numSkills, requestLogs, queryTimes, timeWindow);

    cout << "Output:\n";
    for (int val : result2)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
