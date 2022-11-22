#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
    vector<int> v;
    void inorder(TreeNode *root)
    {
        if (!root)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
public:
    int kthSmallest(TreeNode *root, int k)
    {
        inorder(root);
        return v[k - 1];
    }
};