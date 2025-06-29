#include <iostream>
#include <vector>
using namespace std;

// https://www.fastprep.io/problems/amazon-get-minimum-dock-bays

// GPT Answer

// bool check(vector<int> &truckCargoSize, long maxTurnaroundTime, int d) {
//     priority_queue<int, vector<int>, greater<int>> dockAvailable;
//     int maxTime = 0;
//     int n = truckCargoSize.size();

//     for (int i = 0; i < n; ++i) {
//         if (dockAvailable.size() < d) {
//             dockAvailable.push(truckCargoSize[i]);
//             maxTime = max(maxTime, truckCargoSize[i]);
//         } else {
//             int earliestFree = dockAvailable.top(); dockAvailable.pop();
//             int finish = earliestFree + truckCargoSize[i];
//             maxTime = max(maxTime, finish);
//             dockAvailable.push(finish);
//         }
//     }

//     return maxTime <= maxTurnaroundTime;
// }

// int getMinimumDockBays(vector<int> &truckCargoSize, long maxTurnaroundTime) {
//     int l = 1, r = truckCargoSize.size(), ans = r;

//     while (l <= r) {
//         int mid = l + (r - l) / 2;
//         if (check(truckCargoSize, maxTurnaroundTime, mid)) {
//             ans = mid;
//             r = mid - 1; // try smaller d
//         } else {
//             l = mid + 1; // need more docks
//         }
//     }
//     return ans;
// }

// My Answer
bool check(vector<int> &truckCargoSize, long maxTurnaroundTime, int curr)
{
    priority_queue<int, vector<int>, greater<int>> free;
    int truck = 0, total = 0;
    while (truck < truckCargoSize.size())
    {
        if (truck < curr)
            free.push(truckCargoSize[truck++]);
        else
        {
            int top = free.top();
            free.pop();
            int finishTime = top + truckCargoSize[truck];
            total = max(total, finishTime);
            free.push(finishTime);
            truck++;
        }
    }
    return total <= maxTurnaroundTime;
}

int getMinimumDockBays(vector<int> &truckCargoSize, long maxTurnaroundTime)
{
    int l = 1, u = truckCargoSize.size();
    while (l < u)
    {
        int curr = l + (u - l) / 2;
        if (check(truckCargoSize, maxTurnaroundTime, curr))
            u = curr;
        else
            l = curr + 1;
    }
    return u;
}

void runTest(const vector<int> &truckCargoSize, long maxTime, int expected)
{
    vector<int> input = truckCargoSize;
    int result = getMinimumDockBays(input, maxTime);

    cout << "Input: truckCargoSize = [";
    for (int t : truckCargoSize)
        cout << t << " ";
    cout << "], maxTurnaroundTime = " << maxTime << "\n";

    cout << "Output: " << result << "\n";
    cout << "Expected: " << expected << "\n";
    cout << (result == expected ? "✅ Passed\n\n" : "❌ Failed\n\n");
}

int main()
{
    runTest({3, 4, 3, 2, 3}, 8, 3); // Example 1
    runTest({2, 3, 1}, 7, 1);       // Example 2
    runTest({1, 2, 3, 4, 5}, 6, 4); // Custom
    runTest({5, 5, 5, 5}, 5, 4);    // Each truck needs full time
    runTest({1, 1, 1, 1, 1}, 2, 3); // Tight time constraint
    return 0;
}
