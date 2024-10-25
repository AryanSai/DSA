#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0, u = arr.size() - 1;
        while (l < u) {
            int mid = l + (u - l) / 2;
            if (arr[mid] > arr[mid + 1])
                u = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};