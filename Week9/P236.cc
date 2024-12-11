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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> mp;
        stack<TreeNode*> st;
        mp[root] = nullptr;
        st.push(root);

        while (mp.find(p) == mp.end() || mp.find(q) == mp.end()) {
            TreeNode* top =st.top();
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

        unordered_set<TreeNode*> ancestors;
        while (p) {
            ancestors.insert(p);
            p = mp[p];
        }
        while (ancestors.find(q) == ancestors.end()) 
            q = mp[q]; 
        return q;
    }
};