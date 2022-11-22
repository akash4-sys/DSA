#include "../../headers.h"
#include "../../treestructure.h"

// Insertion in binary search tree

class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *r, int k)
    {
        if(!r)
            return new TreeNode(k);
        auto root = r;
        while(true)
        {
            if(root->val < k)
            {
                if(root->right) root = root->right;
                else
                {
                    root->right = new TreeNode(k);
                    break;
                }
            }
            else
            {
                if(root->left) root = root->left;
                else
                {
                    root->left = new TreeNode(k);
                    break;
                }
            }
        }
        return r;
    }
};


class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int k)
    {
        if(!root)
            return new TreeNode(k);
        if(root->val > k) 
            root->left = insertIntoBST(root->left, k);
        else 
            root->right = insertIntoBST(root->right, k);
        return root;
    }
};

// @lc app=leetcode id=701 lang=cpp