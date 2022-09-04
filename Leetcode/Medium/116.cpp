#include "../../headers.h"

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// BFS
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return nullptr;
        queue<Node *> q{{root}};
        while (!q.empty())
        {
            Node *rightNode = nullptr;
            for (int i = q.size(); i > 0; i--)
            {
                auto curr = q.front();
                q.pop();
                curr->next = rightNode;
                rightNode = curr;
                if (curr->right)
                    q.push(curr->right), q.push(curr->left);
            }
        }
        return root;
    }
};

// DFS

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;
        if (root->left)
        {
            root->left->next = root->right;
            if(root->next)
                root->right->next = root->next->left;
            connect(root->left);
            connect(root->right);
        }
        return root;
    }
};