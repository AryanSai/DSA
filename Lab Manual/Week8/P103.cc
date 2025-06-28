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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> sol;
        if(!root)
            return sol;
        queue<TreeNode*> q;
        q.push(root);
        int i=0;
        while(!q.empty()){
            int siz=q.size();
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
            i++;
            if(i%2!=0)
                sol.push_back(level);
            else{
                reverse(level.begin(), level.end());
                sol.push_back(level);
            }
        }
        return sol;
    }
};