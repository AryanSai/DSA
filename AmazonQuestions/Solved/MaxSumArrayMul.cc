#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> maximizeSum(vector<int> &data)
{
    // store the original indices
    vector<pair<int, int>> ogIndices;
    for (int i = 0; i < data.size(); i++)
        ogIndices.push_back({data[i], i + 1});

    sort(ogIndices.begin(), ogIndices.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first; });

    vector<int> sol;
    for (int i = 0; i < data.size(); i++)
        sol.push_back(ogIndices[i].second);
    return sol;
}

int main()
{
    vector<int> data = {3, 6, 1, 4, 2};
    vector<int> result = maximizeSum(data);

    cout << "Output: [";
    for (int i : result)
        cout << i << " ";
    cout << "]\n"; // Output: [3, 5, 1, 4, 2]
}
