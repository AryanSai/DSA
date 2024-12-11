#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long maxi = 1, siz = 0, left = 0, right = 0, id = 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        while (!q.empty()) {
            siz = q.size();
            left = q.front().second;
            right = q.back().second;
            maxi = max(maxi, right - left + 1);
            for (int i = 0; i < siz; ++i) {
                pair<TreeNode*, int> p = q.front();
                id = p.second - left;
                q.pop();
                if (p.first->left)
                    q.push({p.first->left, (long long)2 * id + 1});
                if (p.first->right)
                    q.push({p.first->right, (long long)2 * id + 2});
            }
        }
        return maxi;
    }
};