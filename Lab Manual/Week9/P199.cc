#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
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
    vector<int> sol;

    void dfs(TreeNode *node, int depth)
    {
        if (!node)
            return;

        // If we're at a new depth level, add the node's value
        if (depth == sol.size())
        {
            sol.push_back(node->val);
        }

        // First visit the right child, then the left child
        dfs(node->right, depth + 1);
        dfs(node->left, depth + 1);
    }

    vector<int> rightSideView(TreeNode *root)
    {
        dfs(root, 0);
        return sol;
    }
};