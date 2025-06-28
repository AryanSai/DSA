#include <iostream>
#include <vector>
#include <string>
using namespace std;

string findNextAttractiveNumber(string num, int k)
{
    string curr = num;
    for (int i = 0; i < num.size() - k; i++)
        if (curr[i] != curr[i + k])
            curr[i + k] = curr[i];
    return curr;
}

void runTest(const string &num, int k, const string &expected)
{
    string result = findNextAttractiveNumber(num, k);
    cout << "Input:    num = \"" << num << "\", k = " << k << endl;
    cout << "Output:   " << result << endl;
    cout << "Expected: " << expected << endl;
    cout << (result == expected ? "✅ Passed\n\n" : "❌ Failed\n\n");
}

int main()
{
    // Test Case 1
    runTest("25252", 2, "25252");

    // Test Case 2
    runTest("43210", 4, "43214");

    runTest("25352", 2, "25454");
    return 0;
}
