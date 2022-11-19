#include "../../headers.h"
#include "../../treestructure.h"

// Binary Search Tree

// Time Complexity - O(N)
// Space Complexity - O(1)
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        while(root)
        {
            if(root->val == val)
                return root;
            root = (root->val > val) ? root->left : root->right;
        }
        return NULL;
    }
};


// Time Complexity - O(N)
// Space Complexity - O(logN)
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (!root)
            return NULL;
        if (root->val == val)
            return root;
        if(root->val > val)
            return searchBST(root->left, val);
        return searchBST(root->right, val);
    }
};