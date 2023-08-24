#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    int x;
    vector<int> solution;
    for (int i = 0; i < nums.size(); i++)
    {
        x = target - nums.at(i);
        for (int j = 1; j < nums.size(); j++)
        {
            if (i != j && x == nums.at(j))
            {
                solution.push_back(i);
                solution.push_back(j);
                return solution;
            }
        }
    }
    return solution;
}

int main()
{
    vector<int> vector1 = {2, 5, 5, 11};
    vector<int> vector;

    cout << "Vector  = ";

    for (int i : vector1)
    {
        cout << i << "  ";
    }

    int target = 10;
    cout << "\nTarget  = " << target;
    vector = twoSum(vector1, target);

    cout << "\nSolution  = ";

    for (int i : vector)
    {
        cout << i << "  ";
    }
    return 0;
}