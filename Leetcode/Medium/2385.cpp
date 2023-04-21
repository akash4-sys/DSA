#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
    int ans = 0, s;
    TreeNode *r = NULL;
    unordered_map<TreeNode*, TreeNode*> par;

    void mapParent(TreeNode *root, TreeNode *p)
    {
        if (!root)
            return;
        if (root->val == s)
            r = root;
        par[root] = p;
        mapParent(root->left, root);
        mapParent(root->right, root);
    }

    void dfs(TreeNode *root, int d)
    {
        if (!root || root->val == -1)
            return;
        ans = max(ans, d);
        root->val = -1;
        dfs(par[root], d + 1);
        dfs(root->left, d + 1);
        dfs(root->right, d + 1);
    }

public:
    int amountOfTime(TreeNode *root, int s)
    {
        this->s = s;
        mapParent(root, NULL);
        dfs(r, 0);
        return ans;
    }
};