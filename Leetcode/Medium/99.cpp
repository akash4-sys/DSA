#include "../../headers.h"
#include "../../treestructure.h"

class Solution 
{
    TreeNode *x, *y, *prev;
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        if (!x && prev->val > root->val)
            x = prev;
        if (x && prev->val > root->val)
            y = root;
        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) 
    {
        prev = new TreeNode(INT_MIN);
        inorder(root);
        swap(x->val, y->val);
    }
};