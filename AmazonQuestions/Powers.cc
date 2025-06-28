#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int maxCircularSubsequence(vector<int>& powers) {
    unordered_map<int, int> freq;

    // Count frequency of each number
    for (int num : powers)
        freq[num]++;

    int maxLen = 0;

    // Try all possible centers x
    for (auto& [x, _] : freq) {
        int total = freq[x];
        if (freq.count(x - 1)) total += freq[x - 1];
        if (freq.count(x + 1)) total += freq[x + 1];

        maxLen = max(maxLen, total);
    }

    return maxLen;
}

int main() {
    vector<int> powers = {4, 3, 5, 1, 2, 1}; // with 2x 2s like in corrected problem

    cout << "Maximum valid circular subsequence length: "
         << maxCircularSubsequence(powers) << endl;

    return 0;
}
