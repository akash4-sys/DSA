#include "../../headers.h"
#include "../../treestructure.h"
// Delete Node in binary search tree
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *r, int k)
    {
        TreeNode *root = r, *par = nullptr;
        while (root && root->val != k)
            par = root, root = (root->val > k) ? root->left : root->right;

        // target Node not found
        if (!root)
            return r;
        
        // target node found with either left subtree or right subtree
        if (!root->left || !root->right)
        {
            auto child = root->left ? root->left : root->right;
            if (!par)
                r = child;
            else if (par->left == root)
                par->left = child;
            else
                par->right = child;
        }
        else            // target node found with both left and right subtree
        {
            auto curr = root;
            par = root, root = root->right;
            while (root->left)
                par = root, root = root->left;
            curr->val = root->val;
            if (par->left == root)
                par->left = root->right;
            else
                par->right = root->right;
        }
        delete root;
        return r;
    }
};

// @lc app=leetcode id=450 lang=cpp