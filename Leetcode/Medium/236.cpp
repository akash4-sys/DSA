#include "../../headers.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool recurse(TreeNode *root, TreeNode *t, vector<TreeNode *> &path)
    {
        if (!root)
            return false;
        path.push_back(root);
        if (root == t)
            return true;
        if (recurse(root->left, t, path) || recurse(root->right, t, path))
            return true;
        path.pop_back();
        return false;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> a, b;
        recurse(root, p, a);
        recurse(root, q, b);
        TreeNode *ans;
        for (int i = 0; i < a.size() && i < b.size() && a[i] == b[i]; i++)
            ans = a[i];
        return ans;
    }
};