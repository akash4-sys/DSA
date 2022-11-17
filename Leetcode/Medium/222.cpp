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
public:
    int countNodes(TreeNode* root)
    {
        if(!root)
            return 0;
        int hl = 0, hr = 0;
        TreeNode *l = root, *r = root;
        for(; l; l = l->left)
            hl++;
        for(; r; r = r->right)
            hr++;
        if(hl == hr)
            return pow(2, hl) - 1;
        return 1 + countNodes(root->right) + countNodes(root->left);
    }
};


// Time Complexity - O(N)
// Space Complexity - O(N)
class Solution 
{
public:
    int countNodes(TreeNode* root)
    {
        if(!root)
            return 0;
        return 1 + countNodes(root->right) + countNodes(root->left);
    }
};


// @lc app=leetcode id=222 lang=cpp