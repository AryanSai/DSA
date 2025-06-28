#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void helper(TreeNode* root, vector<string>& sol, string str){
        if(root!=nullptr){
            str += to_string(root->val);
            if(root->left==nullptr && root->right==nullptr){
                sol.push_back(str);
            }else{
                str += "->" ; 
                helper(root->left, sol, str);
                helper(root->right, sol, str);
            }
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> sol;
        helper(root, sol, "");
        return sol;
    }
};