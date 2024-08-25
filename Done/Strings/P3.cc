#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int l = s.length(), left = 0, right = 0, len = 0;
        unordered_set<char> chars;
        char ch;
        for (int i = 0; i < l; i++)
        {
            ch = s.at(i);
            while (chars.find(ch) != chars.end())
                chars.erase(s[left++]);
            chars.insert(ch);
            right++;
            len = max(len, right - left);
        }
        return len;
    }
    int lengthOfLongestSubstring2(string s)
    {
        int l = s.length(), left = 0, right = 0, len = 0;
        unordered_map<char, int> chars;
        char ch;
        for (int i = 0; i < l; i++)
        {
            ch = s[i];
            if (chars.find(ch) != chars.end() && chars[ch] >= left)
                left = chars[ch] + 1;
            chars[ch] = right;
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};
int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring2("dvdf") << endl;
    return 0;
}