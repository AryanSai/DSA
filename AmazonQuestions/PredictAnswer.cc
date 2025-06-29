#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

vector<int> predictAnswer(vector<int> &stockData, vector<int> &queries)
{
    int n = stockData.size();
    vector<int> prevSmaller(n, -1);
    vector<int> nextSmaller(n, -1);
    stack<int> st;

    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && stockData[st.top()] >= stockData[i])
            st.pop();
        if (!st.empty())
            prevSmaller[i] = st.top();
        st.push(i);
    }

    while (!st.empty())
        st.pop();
    for (int i = n - 1; i >= 0; --i)
    {
        while (!st.empty() && stockData[st.top()] >= stockData[i])
            st.pop();
        if (!st.empty())
            nextSmaller[i] = st.top();
        st.push(i);
    }

    // 3. Answer each query
    vector<int> ans;
    for (int query : queries)
    {
        int i = query - 1; // 1-based to 0-based
        int left = prevSmaller[i];
        int right = nextSmaller[i];

        if (left == -1 && right == -1)
            ans.push_back(-1);
        else if (left == -1)
            ans.push_back(right + 1);
        else if (right == -1)
            ans.push_back(left + 1);
        else if (abs(i - left) <= abs(i - right))
            ans.push_back(left + 1);
        else
            ans.push_back(right + 1);
    }

    return ans;
}

int main()
{
    vector<int> stockData = {5, 6, 8, 4, 9, 10, 8, 3, 6, 4};
    vector<int> queries = {6, 5, 4};
    vector<int> result = predictAnswer(stockData, queries);

    cout << "Output: ";
    for (int day : result)
        cout << day << " ";
    cout << endl;

    // Expected Output: 5 4 8
    return 0;
}