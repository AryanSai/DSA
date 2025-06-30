#include <iostream>
#include <string>
#include <map>
using namespace std;

bool isNearlyIdentical(const string &a, const string &b)
{
    if (a == b)
        return true;

    vector<int> mismatch;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != b[i])
            mismatch.push_back(i);
    }

    if (mismatch.size() != 2)
        return false;

    // check if the mismatch is due to an adjacent swap
    int i = mismatch[0], j = mismatch[1];
    return (j == i + 1) && (a[i] == b[j]) && (a[j] == b[i]);
}

int countSimilarSubstrings(const string &target, const string &content)
{
    int n = content.size(), m = target.size(), count = 0;
    for (int i = 0; i <= n - m; i++)
    {
        string sub = content.substr(i, m);
        if (isNearlyIdentical(target, sub))
            count++;
    }
    return count;
}

void runTest(const string &target, const string &content, int expected)
{
    int result = countSimilarSubstrings(target, content);

    cout << "Target: \"" << target << "\", Content: \"" << content << "\"\n";
    cout << "Output: " << result << ", Expected: " << expected << "\n";
    cout << (result == expected ? "✅ Passed\n\n" : "❌ Failed\n\n");
}

int main()
{
    runTest("moon", "monomon", 2);  // Example 1
    runTest("aaa", "aaaa", 2);      // Example 2
    runTest("abc", "abcabc", 2);    // Direct matches
    runTest("abc", "acbabc", 2);    // Including 1-swap matches
    runTest("abcd", "abcdabcd", 2); // Exact matches only

    return 0;
}
