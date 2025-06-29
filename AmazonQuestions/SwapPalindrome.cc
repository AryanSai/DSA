#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int minSwapsToMakePalindrome(string s)
{
    int n = s.size();
    int count0 = count(s.begin(), s.end(), '0');
    int count1 = n - count0;
    // if (n % 2 == 0 && count0 % 2 == 0)

    int l = 0, u = n - 1, swaps = 0;
    while (l < u)
    {
        if (s[l] == s[u])
        {
            l++;
            u--;
        }
        else
        {
            int mid = l;
            while (mid < u && s[mid] == s[l])
                mid++;
            if (mid == u)
            {
                swap(s[u], s[u-1]);
                swaps++;
            } else {

            }
        }
    }
}

int main()
{
    cout << minSwapsToMakePalindrome("010010") << endl;
    cout << minSwapsToMakePalindrome("1100") << endl;
    cout << minSwapsToMakePalindrome("111000") << endl;
    return 0;
}
