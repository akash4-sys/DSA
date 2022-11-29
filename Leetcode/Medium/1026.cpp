#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
public:
    int maxAncestorDiff(TreeNode *root, int l = INT_MAX, int r = -1)
    {
        if(!root)
            return r - l;
        l = min(l, root->val);
        r = max(r, root->val);
        return max(maxAncestorDiff(root->left, l, r), maxAncestorDiff(root->right, l, r));
    }
};


class Solution
{
    int ans = 0;
    void treePaths(TreeNode *root, int l, int h)
    {
        if(!root)
            return;
        l = min(l, root->val);
        h = max(h, root->val);
        if(!root->left && !root->right)
            ans = max(ans, abs(h - l));
        treePaths(root->left, l, h);
        treePaths(root->right, l, h);
    }

public:
    int maxAncestorDiff(TreeNode *root)
    {
        treePaths(root, INT_MAX, -1);
        return ans;
    }
};

// @lc app=leetcode id=1026 lang=cpp