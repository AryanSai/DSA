#include <iostream>
#include <string>
using namespace std;

int countDominantSubstrings(const string &s)
{
    int n = s.size();
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        vector<int> freq(26, 0);
        for (int j = i; j < n; j++)
        {
            freq[s[j] - 'a']++;

            int len = j - i + 1;
            if (len % 2 == 0)
            {
                int half = len / 2;
                for (int k = 0; k < 26; k++)
                {
                    if (freq[k] == half)
                    {
                        count++;
                        break;
                    }
                }
            }
        }
    }
    return count;
}

// Test runner
void runTest(const string &s, int expected)
{
    int result = countDominantSubstrings(s);

    cout << "Input: \"" << s << "\"\n";
    cout << "Output: " << result << ", Expected: " << expected << endl;
    cout << (result == expected ? "✅ Passed\n\n" : "❌ Failed\n\n");
}

int main()
{
    runTest("aaaaid", 3); // Example 1
    runTest("abab", 4);   // Example 2
    // runTest("aabbcc", 5);  // Additional test
    // runTest("a", 0);       // Odd length - no dominant substrings
    // runTest("abcabcabc", 7); // Extended case
    return 0;
}
