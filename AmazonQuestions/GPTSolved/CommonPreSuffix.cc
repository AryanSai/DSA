#include <iostream>
#include <string>
#include <unordered_set>

// https://algo.monster/problems/amazon-oa-common-prefix

using namespace std;

vector<int> common_prefix(const vector<string> &inputs)
{
    vector<int> results;
    for (const std::string &s : inputs)
    {
        int total = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j + i < n; ++j)
            {
                if (s[j] == s[i + j])
                    total++;
                else
                    break;
            }
        }
        results.push_back(total);
    }

    return results;
}

void runTest(const vector<string> &input, const vector<int> &output)
{
    vector<int> result = common_prefix(input);
    cout << "Input:";
    for (string out : input)
        cout << out << " ";
    cout << endl;

    cout << "Output: ";
    for (int out : result)
        cout << out << " ";
    cout << endl;

    cout << "Expected: ";
    for (int out : output)
        cout << out << " ";
    cout << endl;

    cout << (result == output ? "✅ Passed\n\n" : "❌ Failed\n\n");
}

int main()
{
    vector<string> queryTimes = {"abcabcd"};
    vector<int> expected = {10};
    runTest(queryTimes, expected);

    queryTimes = {"abcabca"};
    expected = {12};
    runTest(queryTimes, expected);

    return 0;
}
