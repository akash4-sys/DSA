#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
    TreeNode *ans;
    int maxD = 0;
    int lvlOrder(TreeNode *root, int lvl)
    {
        maxD = max(maxD, lvl);
        if(!root)
            return lvl;
        int l = lvlOrder(root->left, lvl + 1), r = lvlOrder(root->right, lvl + 1);
        if(l == maxD && r == maxD)
            ans = root;
        return max(l, r);
    }

public:
    TreeNode *subtreeWithAllDeepest(TreeNode *root)
    {
        lvlOrder(root, 0);
        return ans;
    }
};