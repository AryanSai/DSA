#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<int, int> nextAvailable;

int find(int x)
{
    if (!nextAvailable.count(x))
    {
        nextAvailable[x] = x + 1;
        return x;
    }
    return nextAvailable[x] = find(nextAvailable[x]);
}

int makeArrayDistinct(vector<int> &size, vector<int> &cost)
{
    nextAvailable.clear();
    vector<pair<int, int>> shoes;
    int n = size.size();
    for (int i = 0; i < n; i++)
        shoes.emplace_back(cost[i], size[i]);

    sort(shoes.begin(), shoes.end()); // Sort by cost ascending

    int total = 0;
    for (auto [c, s] : shoes)
    {
        int newS = find(s);
        total += (newS - s) * c;
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
