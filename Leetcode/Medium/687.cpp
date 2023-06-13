#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
    int dfs(TreeNode *root, int val)
    {
        if (!root || root->val != val)
            return 0;
        return max(dfs(root->left, val), dfs(root->right, val)) + 1;
    }

public:
    int longestUnivaluePath(TreeNode *root)
    {
        if (!root)
            return 0;
        int val = dfs(root->left, root->val) + dfs(root->right, root->val);
        int l = longestUnivaluePath(root->left);
        int r = longestUnivaluePath(root->right);
        return max({val, l, r});
    }
};