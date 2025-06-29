#include <iostream>
using namespace std;

void generateSubsequences(string s, string current, int index)
{
    if (index == s.size())
    {
        cout << current << endl;
        return;
    }

    // include the current index
    generateSubsequences(s, current + s[index], index + 1);

    // dont include the current index
    generateSubsequences(s, current, index + 1);
}

int main()
{
    generateSubsequences("abc", "", 0);
    return 0;
}