#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
    long ans = 0, mod = 1e9 + 7, total, sum = 0;
    int findSum(TreeNode *root)
    {
        if(!root)
            return 0;
        sum = root->val + findSum(root->left) + findSum(root->right);
        ans = max(ans, sum * (total - sum));
        return sum;
    }

public:
    int maxProduct(TreeNode *root)
    {
        total = findSum(root);
        findSum(root);
        return ans % (int)mod;
    }
};

// @lc app=leetcode id=1339 lang=cpp