#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> getMinMaxExpense(vector<int> &expense, int p)
{
    int m = expense.size();
    vector<int> contrib;

    for (int i = 0; i < m - 1; ++i)
    {
        contrib.push_back(expense[i] + expense[i + 1]);
    }

    sort(contrib.begin(), contrib.end());

    int base = expense[0] + expense[m - 1];

    int minCost = base;
    int maxCost = base;

    for (int i = 0; i < p - 1; ++i)
    {
        minCost += contrib[i];                      // smallest cuts
        maxCost += contrib[contrib.size() - 1 - i]; // largest cuts
    }

    return {minCost, maxCost};
}

int main()
{
    vector<int> expense1 = {1, 2, 3, 2, 5};
    int p1 = 3;
    auto res1 = getMinMaxExpense(expense1, p1);
    cout << "[" << res1[0] << ", " << res1[1] << "]\n"; // [14, 18]

    vector<int> expense2 = {1, 2, 3, 4};
    int p2 = 2;
    auto res2 = getMinMaxExpense(expense2, p2);
    cout << "[" << res2[0] << ", " << res2[1] << "]\n"; // [8, 12]

    return 0;
}
