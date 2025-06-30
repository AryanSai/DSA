#include <iostream>
#include <vector>
using namespace std;

int reduceMemoryUsage(const vector<int> &processes, int m)
{
    int totalMemory = 0, minMemory = 0, toRemove = 0, l = 0;
    for (int memory : processes)
        totalMemory += memory;
    for (int u = 0; u < processes.size(); u++)
    {
        if (u < m)
        {
            toRemove += processes[u];
        }
        else
        {
            toRemove -= processes[l++];
            toRemove += processes[u];
        }
        minMemory = max(minMemory, toRemove);
    }
    return totalMemory - minMemory;
}

// Test runner
void runTest(const vector<int> &processes, int m, int expected)
{
    int result = reduceMemoryUsage(processes, m);

    cout << "Input: processes = [";
    for (int mem : processes)
        cout << mem << " ";
    cout << "], m = " << m << endl;

    cout << "Output: " << result << ", Expected: " << expected << endl;
    cout << (result == expected ? "✅ Passed\n\n" : "❌ Failed\n\n");
}

int main()
{
    runTest({10, 4, 8, 13, 20}, 2, 22);       // Example 1
    runTest({1, 2, 3, 4, 1, 6, 1, 1}, 3, 8);  // test case 2
    runTest({4, 8, 20, 10, 13}, 2, 25);       // test case 4
    return 0;
}
