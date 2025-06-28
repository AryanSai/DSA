#include <iostream>
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
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        TreeNode* curr = root;
        while (curr) {
            if (!curr->left) {
                if (--k == 0)
                    result = curr->val;
                curr = curr->right;
            } else {
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr)
                    pred = pred->right;
                if (pred->right == nullptr) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = nullptr;
                    if (--k == 0)
                        result = curr->val;
                    curr = curr->right;
                }
            }
        }
        return result;
    }
};