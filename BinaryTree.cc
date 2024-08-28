#include <iostream>
#include <queue>

using namespace std;

class BinaryTree
{
public:
    struct Node
    {
        int val;
        Node *left;
        Node *right;

        Node(int data)
        {
            val = data;
            left = right = nullptr;
        }
    };

    Node *root;

    void printValue(Node *node)
    {
        cout << node->val << endl;
    }

    void inorderDFS()
    {
    }

    vector<int> levelOrder(Node *root)
    {
        vector<int> sol;
        if (root == nullptr)
            return sol;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int siz = q.size();
            for (int i = 0; i < siz; i++)
            {
                Node *n = q.front();
                q.pop();
                if (n->left != nullptr)
                    q.push(n->left);
                if (n->right != nullptr)
                    q.push(n->right);
                sol.emplace_back(n->val);
            }
        }
        return sol;
    }

    vector<int> levelOrder2(Node *root)
    {
        vector<int> sol;
        if (root == nullptr)
            return sol;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *n = q.front();
            q.pop();
            if (n->left != nullptr)
                q.push(n->left);
            if (n->right != nullptr)
                q.push(n->right);
            sol.emplace_back(n->val);
        }
        return sol;
    }

    vector<vector<int>> levelOrder_vector(Node *root)
    {
        vector<vector<int>> sol;
        if (root == nullptr)
            return sol;

        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            int siz = q.size();
            vector<int> sub;
            for (int i = 0; i < siz; i++)
            {
                Node *n = q.front();
                q.pop();
                if (n->left != nullptr)
                    q.push(n->left);
                if (n->right != nullptr)
                    q.push(n->right);
                sub.push_back(n->val);
            }
            sol.emplace_back(sub);
        }
        return sol;
    }
};

int main()
{
}