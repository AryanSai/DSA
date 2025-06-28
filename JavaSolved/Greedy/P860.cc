#include <iostream>
#include <vector>

using namespace std;

class P860
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int cash[2] = {0, 0};
        for (int i : bills)
        {
            if (i == 5)
            {
                cash[0] += 1;
            }
            else if (i == 10)
            {
                if (cash[0] <= 0)
                    return false;
                cash[1] += 1;
                cash[0] -= 1;
            }
            else if (i == 20)
            {
                if (cash[1] >= 1 && cash[0] >= 1)
                {
                    cash[1] -= 1;
                    cash[0] -= 1;
                }
                else if (cash[0] >= 3)
                {
                    cash[0] -= 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
    int main()
    {

        return 0;
    }
};