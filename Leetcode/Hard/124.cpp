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
    int ans = INT_MIN;
    int recurse(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = max(recurse(root->left), 0), r = max(recurse(root->right), 0);
        ans = max({ans, r + l + root->val});
        return max(l, r) + root->val;
    }
public:
    int maxPathSum(TreeNode *root)
    {
        recurse(root);
        return ans;
    }
};


class Solution
{
    int ans = INT_MIN;
    int recurse(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = recurse(root->left), r = recurse(root->right);
        ans = max({ans, l + root->val, r + root->val, root->val, r + l + root->val});
        return max(max(l, r) + root->val, root->val);
    }
public:
    int maxPathSum(TreeNode *root)
    {
        recurse(root);
        return ans;
    }
};


// @lc app=leetcode id=124 lang=cpp