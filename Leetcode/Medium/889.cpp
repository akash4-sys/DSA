#include "../../headers.h"
#include "../../treestructure.h"

// Binary Tree From Postorder and Preorder traversal

class Solution
{
    int preI = 0, postI = 0;
public:
    TreeNode *constructFromPrePost(vector<int> &pre, vector<int> &post)
    {
        TreeNode *root = new TreeNode(pre[preI++]);
        if(root->val != post[postI])
            root->left = constructFromPrePost(pre, post);
        if(root->val != post[postI])
            root->right = constructFromPrePost(pre, post);
        postI++;
        return root;
    }
};