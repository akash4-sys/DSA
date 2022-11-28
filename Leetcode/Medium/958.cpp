#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        vector<TreeNode *> q;
        int i = 0;
        q.push_back(root);
        while(i < q.size() && q[i])
        {
            q.push_back(q[i]->left);
            q.push_back(q[i]->right);
            i++;
        }
        while(i < q.size() && !q[i])
            i++;
        return i == q.size();
    }
};

// @lc app=leetcode id=958 lang=cpp