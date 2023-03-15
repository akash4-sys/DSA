#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
public:
    bool isCompleteTree(TreeNode* root)
    {
        vector<TreeNode *> q;
        int i = 0;
        for (q.push_back(root); i < q.size() && q[i]; i++)
            q.push_back(q[i]->left), q.push_back(q[i]->right);
        
        for (; i < q.size() && !q[i]; i++);
        return i == q.size();
    }
};

class Solution
{
    int countN(TreeNode *root)
    {
        return root ? countN(root->left) + countN(root->right) + 1 : 0;
    }

    bool dfs(TreeNode *root, int n, int i)
    {
        if (!root)
            return 1;
        if (i >= n)
            return 0;
        return dfs(root->left, n, (2 * i) + 1) && dfs(root->right, n, (2 * i) + 2);
    }

public:
    bool isCompleteTree(TreeNode* root)
    {
        return dfs(root, countN(root), 0);
    }
};

// @lc app=leetcode id=958 lang=cpp