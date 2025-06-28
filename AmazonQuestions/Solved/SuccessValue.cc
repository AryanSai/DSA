#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getSuccessValue(vector<int> num_viewers, vector<int> queries)
{
    sort(num_viewers.begin(), num_viewers.end(), greater<int>());
    int sum = 0;
    for (int i = 0; i < num_viewers.size(); i++)
    {
        sum += num_viewers[i];
        num_viewers[i] = sum;
    }
    vector<int> sol;
    for (int query : queries)
        sol.push_back(num_viewers[query - 1]);
    return sol;
}

void runTest(vector<int> num_viewers, vector<int> queries, vector<int> expected)
{
    vector<int> result = getSuccessValue(num_viewers, queries);
    cout << "Output:   ";
    for (int r : result)
        cout << r << " ";
    cout << "\nExpected: ";
    for (int e : expected)
        cout << e << " ";
    cout << "\n"
         << (result == expected ? "✅ Passed\n\n" : "❌ Failed\n\n");
}

int main()
{
    // Example 1
    runTest({2, 5, 6, 3, 5}, {2, 3, 5}, {11, 16, 21});

    // Example 2
    runTest({7, 3, 5, 2}, {1, 4}, {7, 17});

    // Example 3
    runTest({7, 5, 6}, {1, 2, 3}, {7, 13, 18});

    return 0;
}
