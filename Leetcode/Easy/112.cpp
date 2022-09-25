#include "../../headers.h"
// @lc app=leetcode id=112 lang=cpp

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
    int tar, ans = 0;
    void checkPath(TreeNode *root, int sum)
    {
        if (!root)
            return;
        sum += root->val;
        if (!root->left && !root->right && sum == tar)
            ans = 1;
        checkPath(root->left, sum);
        checkPath(root->right, sum);
    }

public:
    bool hasPathSum(TreeNode *root, int t)
    {
        tar = t;
        checkPath(root, 0);
        return ans;
    }
};


class Solution
{
public:
    bool hasPathSum(TreeNode *root, int t, int sum = 0)
    {
        if(!root)
            return false;
        sum += root->val;
        if (!root->left && !root->right && sum == t)
            return true;
        return hasPathSum(root->left, t, sum) || hasPathSum(root->right, t, sum);
    }
};

