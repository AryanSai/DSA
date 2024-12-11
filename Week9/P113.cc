#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

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
    vector<vector<int>> sol;

    void bc(TreeNode* root, vector<int>& temp, int target) {
        if (!root)
            return;

        temp.push_back(root->val); 

        if (!root->left && !root->right && target == root->val) {
            sol.push_back(temp); 
        } else {
            if (root->left) 
                bc(root->left, temp, target - root->val);
            if (root->right)
                bc(root->right, temp, target - root->val);
        }

        temp.pop_back();  
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        bc(root, temp, targetSum);
        return sol;
    }
};
