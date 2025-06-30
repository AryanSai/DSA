#include <iostream>
#include <set>

using namespace std;
int main()
{
    vector<int> nums = {2, 4, 1, 4, 7, 8, 6, 3};
    set<int> st(nums.begin(), nums.end());
    for (int num : nums)
    {
        cout << "Num : " << num << endl;
        cout << "Lower : " << *--st.lower_bound(num) << endl;
        cout << "Upper : " << *st.upper_bound(num) << endl;
    }

    return 0;

}