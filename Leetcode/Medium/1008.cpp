#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
    int i = 0;
public:
    TreeNode *bstFromPreorder(vector<int> &preorder, int bound = INT_MAX)
    {
        if(i >= preorder.size() || preorder[i] > bound)
            return NULL;
        TreeNode *root = new TreeNode(preorder[i++]);
        root->left = bstFromPreorder(preorder, root->val);
        root->right = bstFromPreorder(preorder, bound);
        return root;
    }
};