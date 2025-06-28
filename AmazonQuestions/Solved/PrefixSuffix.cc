#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

int splitPrefixSuffix_GPTSolution(const string& categories, int k) {
    int n = categories.size();
    vector<int> prefixCount(n), suffixCount(n);

    // Keep track of distinct characters on the left and right
    unordered_set<char> seenPrefix, seenSuffix;
    vector<int> leftShared(n, 0), rightShared(n, 0);

    // Count unique characters from the left
    for (int i = 0; i < n; ++i) {
        seenPrefix.insert(categories[i]);
        prefixCount[i] = seenPrefix.size();
    }

    // Count unique characters from the right
    seenSuffix.clear();
    for (int i = n - 1; i >= 0; --i) {
        seenSuffix.insert(categories[i]);
        suffixCount[i] = seenSuffix.size();
    }

    // Count character frequency in total
    vector<int> totalFreq(26, 0);
    for (char c : categories) {
        totalFreq[c - 'a']++;
    }

    // Maintain frequency count for prefix
    vector<int> prefixFreq(26, 0);
    int shared = 0, ways = 0;

    for (int i = 0; i < n - 1; ++i) {
        int idx = categories[i] - 'a';
        prefixFreq[idx]++;
        if (prefixFreq[idx] == 1 && totalFreq[idx] > 1) {
            shared++;
        }
        if (prefixFreq[idx] == totalFreq[idx]) {
            shared--;
        }
        if (shared > k) {
            ways++;
        }
    }

    return ways;
}

int splitPrefixSuffix(const string &categories, int k)
{
    unordered_map<char, int> fullfreq, seenfreq;
    set<char> fullset(categories.begin(), categories.end()), seenset;
    for (char c : categories)
        fullfreq[c]++;

    int count = 0;
    for (int i = 0; i < categories.size() - 1; ++i)
    {
        char c = categories[i];
        seenfreq[c]++;
        seenset.insert(c);
        fullfreq[c]--;
        if (fullfreq[c] == 0)
            fullset.erase(c);

        set<char> intersection;
        set_intersection(
            seenset.begin(), seenset.end(),
            fullset.begin(), fullset.end(),
            inserter(intersection, intersection.begin()));

        if (intersection.size() > k)
            count++;
    }

    return count;
}

// Test driver
void runTest(const string &categories, int k, int expected)
{
    int result = splitPrefixSuffix(categories, k);
    cout << "Input: \"" << categories << "\", k = " << k << endl;
    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << (result == expected ? "✅ Passed\n\n" : "❌ Failed\n\n");
}

int main()
{
    runTest("abbcac", 1, 2);
    runTest("abcabc", 2, 1);
    runTest("a", 0, 0);
    runTest("abcxyz", 0, 0);
    runTest("aaaaaa", 0, 5);
    runTest("abcabc", 1, 3);
    runTest("abcabc", 26, 0);
    runTest("abbcac", 1, 2);
    runTest("abababab", 1, 5);
    return 0;
}
