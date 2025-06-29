#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int findNearestMissing(unordered_set<int> &used, int x)
{
    int offset = 0;
    while (true)
    {
        if (!used.count(x + offset))
            return x + offset;
        ++offset;
    }
}

int makeArrayDistinct(vector<int> &size, vector<int> &cost)
{
    vector<pair<int, int>> shoes;
    for (int i = 0; i < size.size(); i++)
        shoes.push_back({size[i], cost[i]});

    sort(shoes.begin(), shoes.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first > b.first; });

    unordered_set<int> usedSizes;
    int total = 0;

    for (auto &p : shoes)
    {
        int s = p.first;
        int c = p.second;

        if (usedSizes.count(s))
        {
            int newS = findNearestMissing(usedSizes, s);
            total += (newS - s) * c;
            usedSizes.insert(newS);
        }
        else
        {
            usedSizes.insert(s);
        }
    }
    return total;
}

void runTest(const vector<int> &size, const vector<int> &cost, int expected)
{
    vector<int> s = size, c = cost; // create copies
    int result = makeArrayDistinct(s, c);

    cout << "Input size: [";
    for (int x : size)
        cout << x << " ";
    cout << "]\n";

    cout << "Input cost: [";
    for (int x : cost)
        cout << x << " ";
    cout << "]\n";

    cout << "Output: " << result << ", Expected: " << expected << "\n";
    cout << (result == expected ? "✅ Passed\n\n" : "❌ Failed\n\n");
}

int main()
{
    runTest({2, 3, 3, 2}, {2, 4, 5, 1}, 7);
    runTest({3, 7, 9, 7, 8}, {5, 2, 5, 7, 5}, 6);
    runTest({1, 1, 1}, {1, 1, 1}, 3);
    runTest({4, 4, 5, 5}, {1, 2, 1, 2}, 4);
    runTest({10, 20, 30}, {1, 1, 1}, 0); // already distinct
    return 0;
}
