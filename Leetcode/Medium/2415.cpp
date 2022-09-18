#include "headers.h"

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
    void dfs(TreeNode *p, TreeNode *q, int lvl)
    {
        if(!p && !q)
            return;
        if(lvl % 2 && p && q)
            swap(p->val, q->val);
        dfs(p->left, q->right, lvl+1);
        dfs(p->right, q->left, lvl+1);
    }

public:
    TreeNode *reverseOddLevels(TreeNode *root)
    {
        if(root->left && root->right)
            dfs(root->left, root->right, 1);
        return root;
    }
};