#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int> &nums, int target)
{
    if (nums.empty())
        return vector<int>({-1, -1});

    int mid = 0, l = 0, u = nums.size() - 1;
    while (l <= u)
    {
        mid = (l + u) / 2;
        if (nums[mid] == target)
            break;
        if (nums[mid] > target)
            u = mid - 1;
        else
            l = mid + 1;
    }

    if (l > u)
        return vector<int>({-1, -1});

    vector<int> sol(2, -1);
    l = mid;
    u = mid;

    while (l >= 0 && nums[l] == target) l--;
    while (u < nums.size() && nums[u] == target) u++;

    sol[0] = l + 1;
    sol[1] = u - 1;
    return sol;
}

int main()
{
    std::vector<int> nums;
    nums.push_back(5);
    nums.push_back(7);
    nums.push_back(7);
    nums.push_back(8);
    nums.push_back(8);
    nums.push_back(10);

    vector<int> sol = searchRange(nums, 8);

    cout << "Range: [" << sol[0] << ", " << sol[1] << "]" << std::endl;

    return 0;
}