#include <iostream>
#include <string>
using namespace std;

// https://www.fastprep.io/problems/amazon-password-strength

int findPasswordStrength(const string &credential)
{
    int count = 0, vowels = 0, consonants = 0;
    for (char c : credential)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            vowels++;
        else
            consonants++;
        if (vowels > 0 && consonants > 0)
        {
            count++;
            vowels = 0;
            consonants = 0;
        }
    }
    return count;
}

void runTest(const string &credential, int expected)
{
    int result = findPasswordStrength(credential);
    cout << "Input: \"" << credential << "\"\n";
    cout << "Output: " << result << ", Expected: " << expected << endl;
    cout << (result == expected ? "✅ Passed\n\n" : "❌ Failed\n\n");
}

int main()
{
    runTest("hackerrank", 3);
    runTest("aeiou", 0);   // Only vowels
    runTest("bcdfg", 0);   // Only consonants
    runTest("abcde", 2);   // One possible valid split: "abc", "de"
    runTest("aebcdfg", 1); // aebcdfg
    return 0;
}
