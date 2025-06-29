#include <iostream>
#include <vector>
using namespace std;

int getMaxIncrements(vector<int> scores) {
    int n = scores.size();
    unordered_map<int, int> freqMap;
    int maxFreq = 0;
    
    for (int score : scores) {
        freqMap[score]++;
        if (freqMap[score] > maxFreq)
            maxFreq = freqMap[score];
    }
    
    return n - maxFreq;
}
void runTest(const vector<int>& scores, int expected) {
    vector<int> input = scores;  // Create a copy in case implementation modifies it
    int result = getMaxIncrements(input);

    cout << "Input: [";
    for (int x : scores) cout << x << " ";
    cout << "]\n";

    cout << "Output: " << result << "\n";
    cout << "Expected: " << expected << "\n";
    cout << (result == expected ? "✅ Passed\n\n" : "❌ Failed\n\n");
}

int main() {
    runTest({2, 1, 3}, 2);
    runTest({2, 1, 1, 2}, 2);
    runTest({2, 3, 1, 5, 4}, 4);
    runTest({1, 1, 1, 1}, 0);         // All elements same
    runTest({5, 4, 3, 2, 1}, 4);      // Sorted descending → reversed
    runTest({10, 20}, 1);            // Simple 2 element case

    return 0;
}
