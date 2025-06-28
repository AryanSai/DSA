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

class Solution
{
public:
    TreeNode *build(vector<int>::iterator start, vector<int>::iterator end)
    {
        if (start == end)
            return nullptr;
        auto i = max_element(start, end);
        TreeNode *root = new TreeNode(*i);
        root->left = build(start, i);
        root->right = build(i + 1, end);
        return root;
    }

    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return build(nums.begin(), nums.end());
    }
};