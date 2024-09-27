#include <iostream>
#include <stack>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    pair<int, int> dir[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
    set<pair<int, int>> visit;
    void bfs(vector<vector<char>>& grid, int row, int col) {
        queue<pair<int, int>> q;
        q.push({row, col});
        visit.insert({row, col}); 
        while (!q.empty()) {
            pair<int, int> front = q.front();
            q.pop();
            for (pair<int, int> d : dir) {
                int r = front.first + d.first, c = front.second + d.second;
                if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() &&
                    grid[r][c] == '1' && visit.find({r, c}) == visit.end()) {
                    q.push({r, c});
                    visit.insert({r, c});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++) 
            for (int j = 0; j < grid[0].size(); j++) 
                if (grid[i][j] == '1' && visit.find({i, j}) == visit.end()) {
                    bfs(grid, i, j);
                    count++; 
                }
        return count;
    }
};