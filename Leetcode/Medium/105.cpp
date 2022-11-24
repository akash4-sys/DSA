#include "../../headers.h"
#include "../../treestructure.h"

// @ Binary Tree from inorder and preorder

// @ Don't pass the value of i as a parameter to function (call by value) as the updated value from left is needed in right so call by value won't work
// @ Call by reference works

// Time Complexity - O(N)
// Space Complexity - O(H)

class Solution
{
    int i = 0;
    unordered_map<int, int> inorder;
    TreeNode *build(vector<int> &preorder, int l, int r)
    {
        if(l > r)
            return NULL;
        int val = preorder[i++];
        TreeNode *root = new TreeNode(val);
        root->left = build(preorder, l, inorder[val] - 1);
        root->right = build(preorder, inorder[val] + 1, r);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &in)
    {
        for(int i = 0; i < in.size(); i++)
            inorder[in[i]] = i;
        return build(preorder, 0, in.size() - 1);
    }
};