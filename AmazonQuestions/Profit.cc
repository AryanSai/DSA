#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculateMaximumProfitDP(vector<int> price, vector<int> futurePrice, int principle) {
    vector<pair<int, int>> stocks; // {price, profit}
    for (int i = 0; i < price.size(); ++i) {
        int profit = futurePrice[i] - price[i];
        if (profit > 0 && price[i] <= principle) {
            stocks.push_back({price[i], profit});
        }
    }
    
    vector<int> dp(principle + 1, 0);
    for (auto& [cost, profit] : stocks) {
        for (int w = principle; w >= cost; --w) {
            dp[w] = max(dp[w], dp[w - cost] + profit);
        }
    }
    return dp[principle];
}

int calculateMaximumProfit(vector<int> price, vector<int> futurePrice, int principle)
{
    int n = price.size(), maxProfit = 0;
    vector<pair<int, int>> costToProfit;
    for (int i = 0; i < n; i++)
    {
        if (price[i] <= principle && futurePrice[i] - price[i] > 0)
            costToProfit.push_back({price[i], futurePrice[i] - price[i]});
    }

    sort(costToProfit.begin(), costToProfit.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
        if(a.second == b.second)
            return a.first < b.first;
        return a.second > b.second; });

    for (const auto &[cost, profit] : costToProfit)
    {
        if (cost <= principle)
        {
            principle -= cost;
            maxProfit += profit;
        }
    }
    return maxProfit;
}

void runTest(const vector<int> &price, const vector<int> &futurePrice, int principle, int expected)
{
    int result = calculateMaximumProfitDP(price, futurePrice, principle);

    cout << "Input:\nprice = [";
    for (int x : price)
        cout << x << " ";
    cout << "]\nfuturePrice = [";
    for (int x : futurePrice)
        cout << x << " ";
    cout << "]\nprinciple = " << principle << "\n";

    cout << "Output: " << result << ", Expected: " << expected << "\n";
    cout << (result == expected ? "✅ Passed\n\n" : "❌ Failed\n\n");
}

int main()
{
    runTest({10, 50, 30, 40, 70}, {100, 40, 50, 30, 90}, 100, 110);
    return 0;
}
