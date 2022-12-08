#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
    int moves(TreeNode *root, int &m)
    {
        if(!root)
            return 0;
        int left = moves(root->left, m);
        int right = moves(root->right, m);
        m += abs(left) + abs(right);
        return root->val + left + right - 1;
    }

public:
    int distributeCoins(TreeNode *root)
    {
        int m = 0;
        moves(root, m);
        return m;
    }
};