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
    bool solve(TreeNode *p, TreeNode *q)
    {
        if(!p && !q)
            return true;
        return p && q && p->val == q->val && solve(p->left, q->left) && solve(p->right, q->right);
    }

public:
    bool isSubtree(TreeNode *p, TreeNode *q)
    {
        return solve(p, q) || (p && (isSubtree(p->left, q) || isSubtree(p->right, q)));
    }
};