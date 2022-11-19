#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
    int ans = 0;
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = dfs(root->left), r = dfs(root->right);
        ans += abs(l - r);
        return l + r + root->val;
    }

public:
    int findTilt(TreeNode *root)
    {
        dfs(root);
        return ans;
    }
};