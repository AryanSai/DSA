#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int candidate, count = 0;
        for (int i : nums)
        {
            if (count == 0)
            {
                candidate = i;
                count++;
            }
            else if (i == candidate)
                count++;
            else
                count--;
        }
        return candidate;
    }
};