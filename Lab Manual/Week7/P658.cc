#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if (x < arr[0])
            return vector<int>(arr.begin(), arr.begin() + k);
        if (x >= arr[arr.size() - 1]) 
            return vector<int>(arr.end() - k, arr.end());
        int l = 0, u = arr.size() - 1;
        while (u - l + 1 > k) {
            if (abs(arr[l] - x) > abs(arr[u] - x)) 
                l++;
            else 
                u--;
        }
        return vector<int>(arr.begin() + l, arr.begin() + u + 1);
    }
};