#include "../../headers.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if ((p && !q) || (q && !p))
            return false;

        if (p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        return false;
    }
};

// Something is wrong
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p || !q || p->val != q->val)
            return false;
        queue<TreeNode *> a, b;
        a.push(p);
        b.push(p);
        while (!a.empty() && !b.empty())
        {
            TreeNode *x = a.front(), *y = b.front();
            a.pop();
            b.pop();
            if ((x->val != y->val) || (x->left != y->left) || (x->right != y->right))
                return false;
            if (x->left)
            {
                a.push(x->left);
                b.push(y->left);
            }
            if (x->right)
            {
                a.push(x->right);
                b.push(y->right);
            }
        }
        if (a.empty() != b.empty())
            return false;
        return true;
    }
};