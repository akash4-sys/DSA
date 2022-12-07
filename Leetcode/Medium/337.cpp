#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
    unordered_map<TreeNode*, int> ump;
public:
    int rob(TreeNode *root)
    {
        if(!root)
            return 0;
        if(ump.count(root))
            return ump[root];
        int x = 0;
        if(root->left)
            x += rob(root->left->left) + rob(root->left->right);
        if(root->right)
            x += rob(root->right->left) + rob(root->right->right);
        return ump[root] = max(x + root->val, rob(root->left) + rob(root->right));
    }
};


class Solution
{
public:
    int rob(TreeNode *root, int take = 1)
    {
        if(!root)
            return 0;
        int x = take ? rob(root->left, 0) + rob(root->right, 0) + root->val : 0;
        return max(x, rob(root->left, 1) + rob(root->right, 1));
    }
};