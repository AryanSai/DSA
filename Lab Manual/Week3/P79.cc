#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (board[i][j] == word[0] && backtrack(board, word, i, j, 0))
                    return true;
        return false;
    }

private:
    bool backtrack(vector<vector<char>>& board, string& word, int i, int j,
                   int index) {
        if (index == word.size())
            return true;

        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() ||
            board[i][j] != word[index])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';

        for (auto d : dir)
            if (backtrack(board, word, i + d.first, j + d.second, index + 1))
                return true;

        board[i][j] = temp;
        return false;
    }
};
