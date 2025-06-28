#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//solved by deep seek
int minimizeVariation(vector<int> &productSize)
{
    sort(productSize.begin(), productSize.end());
    int n = productSize.size();
    if (n == 0)
        return 0;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + (productSize[j] - productSize[i]);
        }
    }

    return dp[0][n - 1];
}

void runTest(vector<int> productSize, int expected)
{
    int result = minimizeVariation(productSize);
    cout << "Output: " << result << ", Expected: " << expected << endl;
    cout << (result == expected ? "✅ Passed\n\n" : "❌ Failed\n\n");
}

int main()
{
    runTest({3, 1, 2}, 3);              // Example 1
    runTest({6, 1, 4, 2}, 9);           // Example 2/4
    runTest({4, 5, 4, 2, 6, 1, 1}, 16); // Example 3
    runTest({3, 1, 3, 3, 6, 6}, 11);    // Example 5
    runTest({6, 1, 4, 2}, 9);           // Increasing large items

    return 0;
}