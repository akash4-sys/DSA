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
    TreeNode *pruneTree(TreeNode *root)
    {
        if(!root)
            return NULL;
        root->right = pruneTree(root->right);
        if(!root->left && !root->right && !root->val)
            root = NULL;
        return root;
    }
};