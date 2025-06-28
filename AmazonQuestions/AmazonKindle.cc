#include <iostream>
#include <vector>

using namespace std;

long long dp(int l, int r, int k, vector<int>& cost, int pairCost, vector<vector<vector<long long>>>& memo) {
    if (l > r) return 0;
    if (memo[l][r][k] != -1) return memo[l][r][k];

    // Option 1: take left
    long long res = cost[l] + dp(l + 1, r, k, cost, pairCost, memo);

    // Option 2: take right
    res = min(res, (long long)cost[r] + dp(l, r - 1, k, cost, pairCost, memo));

    // Option 3: use pairCost (if possible)
    if (l < r && k > 0) {
        res = min(res, (long long)pairCost + dp(l + 1, r - 1, k - 1, cost, pairCost, memo));
    }

    return memo[l][r][k] = res;
}

long long minTotalCost2(vector<int>& cost, int pairCost, int k) {
    int n = cost.size();
    vector<vector<vector<long long>>> memo(n, vector<vector<long long>>(n, vector<long long>(k + 1, -1)));
    return dp(0, n - 1, k, cost, pairCost, memo);
}

long long minTotalCost1(vector<int> &cost, int pairCost, int k) {
    int left = 0, right = cost.size() - 1;
    long long minCost = 0;

    while (left <= right) {
        // Try to apply pairCost when valid and beneficial
        if (left < right && k > 0 && pairCost < cost[left] + cost[right]) {
            minCost += pairCost;
            left++;
            right--;
            k--;
        } else {
            // Choose the cheaper of left or right book
            if (cost[left] < cost[right]) {
                minCost += cost[left++];
            } else {
                minCost += cost[right--];
            }
        }
    }

    return minCost;
}

long long minTotalCost(vector<int> &cost, int pairCost, int k)
{
    long long minCost = 0;
    int n = cost.size();
    int left = 0, right = n - 1, remaining = n % k, possiblePairs = n - remaining;
    while (remaining > 0)
    {
        if (cost[left] < cost[right])
        {
            minCost += cost[left++];
        }
        else
        {
            minCost += cost[right--];
        }
        remaining--;
    }
    while (left <= right && k > 0)
    {
        if (pairCost < cost[right] + cost[left])
        {
            minCost += pairCost;
            left++;
            right--;
            k--;
        }
        else if (cost[left] < cost[right])
        {
            minCost += cost[left++];
        }
        else
        {
            minCost += cost[right--];
        }
    }
    return minCost;
}

int main()
{
    // Sample input
    int n = 5;
    vector<int> cost = {9, 11, 13, 15, 17};
    int pairCost = 6;
    int k = 2;

    // Call the function
    long long result = minTotalCost2(cost, pairCost, k);

    // Output the result
    cout << "Minimum total cost: " << result << endl;

    return 0;
}
