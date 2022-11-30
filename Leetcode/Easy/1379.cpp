#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
public:
    TreeNode *getTargetCopy(TreeNode *root, TreeNode *c, TreeNode *t)
    {
        if(!root)
            return NULL;
        if(root->val == t->val)
            return c;
        auto a = getTargetCopy(root->left, c->left, t);
        auto b = getTargetCopy(root->right, c->right, t);
        return a ? a : b;
    }
};


class Solution
{
    int getTargetVal(TreeNode *root, TreeNode *t)
    {
        if(!root)
            return -1;
        if(root->val == t->val)
            return t->val;
        int a = getTargetVal(root->left, t);
        int b = getTargetVal(root->right, t);
        return a == -1 ? b : a;
    }

    TreeNode *targetRef(TreeNode *root, int k)
    {
        if(!root)
            return NULL;
        if(root->val == k)
            return root;
        auto a = targetRef(root->left, k);
        auto b = targetRef(root->right, k);
        return a ? a : b;
    }

public:
    TreeNode *getTargetCopy(TreeNode *p, TreeNode *q, TreeNode *t)
    {
        int val = getTargetVal(p, t);
        return targetRef(q, val);
    }
};