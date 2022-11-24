#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
    unordered_map<int, int> inorder;
    TreeNode *build(vector<int> &postorder, int &i, int l, int r)
    {
        if(l > r)
            return NULL;
        int val = postorder[i--];
        TreeNode *root = new TreeNode(val);
        root->right = build(postorder, i, inorder[val] + 1, r);
        root->left = build(postorder, i, l, inorder[val] - 1);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &in, vector<int> &postorder)
    {
        for(int i = 0; i < in.size(); i++)
            inorder[in[i]] = i;
        int i = in.size() - 1;
        return build(postorder, i, 0, in.size() - 1);
    }
};