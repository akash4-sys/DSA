#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
    int ans = INT_MAX, x = -1;
public:
    int getMinimumDifference(TreeNode *root)
    {
        if(root->left)
            getMinimumDifference(root->left);
        if(x >= 0)
            ans = min(ans, root->val - x);
        x = root->val;
        if(root->right)
            getMinimumDifference(root->right);
        return ans;
    }
};