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
    int mainRoot = 1;
public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (!root)
            return root;
        if(mainRoot && depth == 1)
        {
            TreeNode *t = new TreeNode(val);
            t->left = root;
            return t;
        }
        if (depth - 1 == 1)
        {
            TreeNode *t = root->left;
            root->left = new TreeNode(val);
            root->left->left = t;
            t = root->right;
            root->right = new TreeNode(val);
            root->right->right = t;
        }
        mainRoot = 0;
        addOneRow(root->left, val, depth - 1);
        addOneRow(root->right, val, depth - 1);
        return root;
    }
};

// @lc app=leetcode id=623 lang=cpp