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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> sol;
        if(root==nullptr)
            return sol;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int siz = q.size();
            vector<int> level;
            for(int i=0;i<siz;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=nullptr)
                    q.push(node->left);
                if(node->right!=nullptr)
                    q.push(node->right);
                level.push_back(node->val);
            }
            sol.push_back(level);
        }
        return sol;
    }
};