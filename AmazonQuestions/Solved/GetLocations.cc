#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> getFinalLocations(vector<int> locations, vector<int> movedFrom, vector<int> movedTo)
{
    unordered_set<int> locationSet(locations.begin(), locations.end());
    for (int i = 0; i < movedFrom.size(); i++)
    {
        locationSet.erase(movedFrom[i]);
        locationSet.insert(movedTo[i]);
    }
    vector<int> sol(locationSet.begin(), locationSet.end());
    sort(sol.begin(), sol.end());
    return sol;
}

// Test runner
void runTest(vector<int> locations, vector<int> movedFrom, vector<int> movedTo, vector<int> expected)
{
    vector<int> result = getFinalLocations(locations, movedFrom, movedTo);

    cout << "Input:\n  locations = [";
    for (int x : locations)
        cout << x << " ";
    cout << "]\n  movedFrom = [";
    for (int x : movedFrom)
        cout << x << " ";
    cout << "]\n  movedTo = [";
    for (int x : movedTo)
        cout << x << " ";
    cout << "]\n";

    cout << "Output: [";
    for (int x : result)
        cout << x << " ";
    cout << "]\n";

    cout << "Expected: [";
    for (int x : expected)
        cout << x << " ";
    cout << "]\n";

    cout << (result == expected ? "✅ Passed\n\n" : "❌ Failed\n\n");
}

int main()
{
    runTest({1, 7, 6, 8}, {1, 7, 2}, {2, 9, 5}, {5, 6, 8, 9});
    runTest({1, 2, 3, 4}, {1, 2, 3}, {5, 6, 7}, {4, 5, 6, 7});
    runTest({1, 2, 4, 10}, {10}, {3}, {1, 2, 3, 4});
    runTest({1, 7, 6, 4}, {1, 7, 2}, {2, 9, 5}, {4, 5, 6, 9});
    return 0;
}
