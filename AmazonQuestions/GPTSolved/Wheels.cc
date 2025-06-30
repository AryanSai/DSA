#include <iostream>
#include <vector>
using namespace std;

vector<int> countWaysToSelectFleet(const vector<int> &wheels)
{
    vector<int> sol;
    for (int wheel : wheels)
    {
        if (wheel % 2 != 0)
            sol.push_back(0);
        else
            sol.push_back((wheel / 2) / 2 + 1);
    }
    return sol;
}

// Helper to run a single test case
void runTest(const vector<int> &wheels, const vector<int> &expected)
{
    vector<int> result = countWaysToSelectFleet(wheels);

    cout << "Input: wheels = [";
    for (auto w : wheels)
        cout << w << " ";
    cout << "]\n";

    cout << "Output: [";
    for (auto r : result)
        cout << r << " ";
    cout << "]\n";

    cout << "Expected: [";
    for (auto e : expected)
        cout << e << " ";
    cout << "]\n";

    cout << (result == expected ? "✅ Passed\n\n" : "❌ Failed\n\n");
}

int main()
{
    runTest({6, 3, 2}, {2, 0, 1});
    runTest({4, 5, 6}, {2, 0, 2});
    runTest({1, 8, 10}, {0, 3, 3}); 
    return 0;
}
