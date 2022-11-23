#include "../../headers.h"
#include "../../treestructure.h"

// @ What we are doing here is that we are running from the same old path sum
// @ logic just from each and every node

// Time Complexity - O(logN) ~ O(N^2)
// Space Complexity - O(logN)
class Solution
{
    long ans = 0;
    void dfs(TreeNode *root, long t)
    {
        if(!root)
            return;
        t -= root->val;
        ans += !t;
        dfs(root->left, t);    
        dfs(root->right, t);    
    }

public:
    int pathSum(TreeNode *root, int t)
    {
        if(!root)
            return 0;
        dfs(root, t);
        pathSum(root->left, t);
        pathSum(root->right, t);
        return ans;
    }
};