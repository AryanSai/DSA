#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calcMinimumAllocation(vector<int> &initialSpeed, vector<int> &extraBoost)
{
    vector<pair<int, int>> speeds;
    int totalSpeed = 0, n = initialSpeed.size();
    for (int i = 0; i < n; i++)
    {
        speeds.push_back({extraBoost[i], initialSpeed[i]});
        totalSpeed += initialSpeed[i];
    }

    sort(speeds.begin(), speeds.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
        if(a.first == b.first)
            return a.second > b.second;
        return a.first > b.first; });

    int boostedTotal = 0;
    for (int i = 0; i < n; i++)
    {

        boostedTotal += (speeds[i].first + speeds[i].second);
        totalSpeed -= speeds[i].second;
        if (boostedTotal > totalSpeed)
        {
            return i + 1;
        }
    }
    return -1;
}

void runTest(vector<int> init, vector<int> boost, int expected)
{
    int result = calcMinimumAllocation(init, boost);
    cout << "Initial Speed: ";
    for (int i : init)
        cout << i << " ";
    cout << "\nExtra Boost: ";
    for (int i : boost)
        cout << i << " ";
    cout << "\nOutput: " << result << ", Expected: " << expected;
    cout << (result == expected ? " ✅ Passed\n\n" : " ❌ Failed\n\n");
}

int main()
{
    runTest({4, 5, 4}, {2, 1, 2}, 2);       // Example from image
    runTest({3, 4, 5, 6}, {3, 2, 1, 1}, 2); // Sample input from image
    runTest({1, 1, 1}, {10, 10, 10}, 1);    // First robot alone is enough
    runTest({10, 10, 10}, {1, 1, 1}, 2);    
    return 0;
}
