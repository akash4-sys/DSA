#include "../../headers.h"
#include "../../treestructure.h"

// 0 - go left
// 1 - go right

class Solution
{
    int ans = 0;
    void zigZag(TreeNode *root, int dir, int depth)
    {
        if(!root)
            return;
        ans = max(ans, depth);
        if(dir)
            zigZag(root->right, 0, depth + 1), zigZag(root->left, 1, 1);
        else
            zigZag(root->left, 1, depth + 1), zigZag(root->right, 0, 1);
    }

public:
    int longestZigZag(TreeNode *root)
    {
        zigZag(root, 0, 0);
        zigZag(root, 1, 0);
        return ans;
    }
};



// TLE
class Solution
{
    int ans = 0;
    // max zigzag distance from a given root node
    void zigZag(TreeNode *root, int dir, int depth)
    {
        if (!root)
            return;
        ans = max(ans, depth);
        if (dir)
            zigZag(root->right, 0, depth + 1);
        else
            zigZag(root->left, 1, depth + 1);
    }

    // find max distance from each and every root node
    void longest(TreeNode *root)
    {
        if (!root)
            return;
        zigZag(root, 0, 0);
        zigZag(root, 1, 0);
        longest(root->left);
        longest(root->right);
    }

public:
    int longestZigZag(TreeNode *root)
    {
        longest(root);
        return ans;
    }
};

// @lc app=leetcode id=1372 lang=cpp