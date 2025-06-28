#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> sol;
        if (root == nullptr)
            return sol;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int siz = q.size();
            vector<int> sub;
            for (int i = 0; i < siz; i++) {
                TreeNode* n = q.front();
                q.pop();
                if (n->left != nullptr)
                    q.push(n->left);
                if (n->right != nullptr)
                    q.push(n->right);
                sub.push_back(n->val);
            }
            sol.insert(sol.begin(), sub);
        }
        return sol;
    }
};