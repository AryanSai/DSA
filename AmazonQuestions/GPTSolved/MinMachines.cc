#include <vector>
#include <iostream>

using namespace std;

int findMinimumMachinesSize(vector<int> machineCapacity)
{
    int n = machineCapacity.size();
    if (n == 0)
        return 0;

    vector<int> b; //removing duplicates
    b.push_back(machineCapacity[0]);
    for (int i = 1; i < n; i++)
    {
        if (machineCapacity[i] != machineCapacity[i - 1])
            b.push_back(machineCapacity[i]);
    }

    int m = b.size();
    if (m <= 2)
        return m;

    vector<int> c;
    c.push_back(b[0]);
    for (int i = 1; i < m - 1; i++)
    {
        if ((b[i] > b[i - 1] && b[i] > b[i + 1]) || (b[i] < b[i - 1] && b[i] < b[i + 1]))
        {
            c.push_back(b[i]);
        }
    }
    c.push_back(b[m - 1]);

    return c.size();
}

int main()
{
    vector<int> machineCapacity = {1, 2, 2, 1, 1};
    cout << findMinimumMachinesSize(machineCapacity) << endl;

    machineCapacity = {5, 4, 0, 3, 3, 1};
    cout << findMinimumMachinesSize(machineCapacity) << endl;

    machineCapacity = {6, 4, 4, 3, 3, 2};
    cout << findMinimumMachinesSize(machineCapacity) << endl;
}

// Explanation
// Removing Consecutive Duplicates: The algorithm starts by processing the input array to remove consecutive duplicates. For example, the array [1, 2, 2, 1, 1] becomes [1, 2, 1].

// Handling Small Arrays: If the processed array has 1 or 2 elements, the result is the array length itself. For instance, [1, 2] remains as 2 because the sum of absolute differences is |1-2| = 1.

// Identifying Extrema: For longer arrays, the algorithm scans the processed array to find local maxima and minima. A local maximum is an element greater than its neighbors, and a local minimum is an element smaller than its neighbors. For example, in [1, 3, 2], the element 3 is a local maximum.

// Constructing Result: The result sequence is constructed by including the first element, all identified local extrema, and the last element. For [1, 3, 2], the result is [1, 3, 2] with length 3. The sum of absolute differences is |1-3| + |3-2| = 2 + 1 = 3, matching the original sum.

// This approach efficiently minimizes the number of machines while preserving the original sum of absolute differences by leveraging the properties of local extrema and sequence monotonicity. The complexity is linear, O(n), making it suitable for large inputs.

