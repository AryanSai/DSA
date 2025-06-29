#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct Product
{
    long size;
    int cost;
};

// Disjoint-set style map with path compression
unordered_map<long, long> nextAvailable;

// Comparison function for sorting
bool comp(Product &p1, Product &p2)
{
    if (p1.cost == p2.cost)
        return p1.size < p2.size;
    return p1.cost > p2.cost; // Descending by cost
}

// Function to find the next available size ≥ x
long find(long x)
{
    if (!nextAvailable.count(x))
    {
        nextAvailable[x] = x + 1;
        return x;
    }
    return nextAvailable[x] = find(nextAvailable[x]);
}

long getMinimalCost(vector<int> &size, vector<int> &cost)
{
    int n = size.size();
    vector<Product> products(n);

    for (int i = 0; i < n; ++i)
        products[i] = {size[i], cost[i]};

    // Sort in descending order of cost, then ascending by size
    sort(products.begin(), products.end(), comp);

    long totalCost = 0;

    for (const auto &p : products)
    {
        long newSize = find(p.size);
        totalCost += (newSize - p.size) * p.cost;
    }

    return totalCost;
}

// Example usage
int main()
{
    vector<int> size = {3, 7, 9, 7, 8};
    vector<int> cost = {5, 2, 5, 7, 5};

    cout << getMinimalCost(size, cost) << endl; // Output: 6

    size = {2, 3, 3, 2};
    cost = {2, 4, 5, 1};

    cout << getMinimalCost(size, cost) << endl; // Output: 7

    return 0;
}
