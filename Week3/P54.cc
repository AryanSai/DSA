#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> sol;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = n - 1, up = 0, down = m - 1, i = 0, j = 0;
        while (left <= right && up <= down) {
            for (j = left; j <= right; j++) {
                sol.push_back(matrix[up][j]);
            }
            up++;
            for (i = up; i <= down; i++) {
                sol.push_back(matrix[i][right]);
            }
            right--;
            if (up <= down) {
                for (j = right; j >= left; j--) {
                    sol.push_back(matrix[down][j]);
                }
                down--;
            }
            if (left <= right) {
                for (i = down; i >= up; i--) {
                    sol.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return sol;
    }
};