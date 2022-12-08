#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
    string leafs(TreeNode *root)
    {
        if(!root)
            return "";
        if(!root->left && !root->right)
            return to_string(root->val) + "-";
        return leafs(root->left) + leafs(root->right);
    }

public:
    bool leafSimilar(TreeNode *p, TreeNode *q)
    {
        string s = leafs(p), r = leafs(q);
        return s == r;
    }
};


// @lc app=leetcode id=872 lang=cpp