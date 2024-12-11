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
    vector<int> sol;
    unordered_map<TreeNode*, TreeNode*> mp;
    unordered_set<TreeNode*> visited; 
    void dfs(TreeNode* node, int k, int depth) {
        if (!node || visited.count(node)) 
            return;
        visited.insert(node); 
        if (depth == k) { 
            sol.push_back(node->val);
            return;
        }
        dfs(node->left, k, depth + 1);
        dfs(node->right, k, depth + 1);
        if (mp.count(node)) // check if parent exists
            dfs(mp[node], k, depth + 1);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        stack<TreeNode*> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode* top = st.top();
            st.pop();
            if (top->left) {
                mp[top->left] = top;
                st.push(top->left);
            }
            if (top->right) {
                mp[top->right] = top;
                st.push(top->right);
            }
        }
        dfs(target, k, 0);
        return sol;
    }
};
