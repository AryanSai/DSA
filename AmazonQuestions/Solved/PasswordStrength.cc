#include <iostream>
#include <string>
#include <unordered_set>

// https://algo.monster/problems/amazon-oa-find-password-strength

using namespace std;

// TODO: Implement this function
int findPasswordStrength(const string &password)
{
    int sum = 0;
    for (int i = 0; i < password.size(); i++)
    {
        unordered_set<char> st;
        st.insert(password[i]);
        sum += 1;
        for (int j = i + 1; j < password.size(); j++)
        {
            st.insert(password[j]);
            sum += st.size();
        }
    }
    return sum;
}

void runTest(const string &password, int expected)
{
    int result = findPasswordStrength(password);
    cout << "Input: \"" << password << "\"\n";
    cout << "Output: " << result << ", Expected: " << expected << endl;
    cout << (result == expected ? "✅ Passed\n\n" : "❌ Failed\n\n");
}

int main()
{
    runTest("good", 16);
    runTest("test", 19);
    runTest("aa", 3);
    runTest("abc", 10);  // Explanation: a=1, b=1, c=1, ab=2, bc=2, abc=3 → total = 10
    runTest("abcd", 20); // All substrings of length 1 to 4, distinct chars
    return 0;
}
