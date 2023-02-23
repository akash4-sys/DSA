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

class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *rightMost = new Node(0);
        rightMost->next = root;
        while (rightMost->next)
        {
            auto tail = rightMost, r = rightMost->next;
            rightMost->next = NULL;
            for (; r; r = r->next)
            {
                if (r->left)
                    tail->next = r->left, tail = tail->next;
                if (r->right)
                    tail->next = r->right, tail = tail->next;
            }
        }
        return root;
    }
};


class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return NULL;
        queue<Node *> q{{root}};
        while (!q.empty())
        {
            Node *rightMost = NULL;
            for (int i = q.size(); i; i--)
            {
                auto curr = q.front();
                q.pop();
                curr->next = rightMost;
                rightMost = curr;
                if (curr->right)
                    q.push(curr->right);
                if (curr->left)
                    q.push(curr->left);
            }
        }
        return root;
    }
};