#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
    pair<int, int> find(TreeNode *root, int x, int lvl, int p)
    {
        if (!root)
            return {-1, -1};
        if(root->val == x)
            return {p, lvl};
        auto xp = find(root->left, x, lvl + 1, root->val);
        auto yp = find(root->right, x, lvl + 1, root->val);
        return xp.first == -1 ? yp : xp;
    }

public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        auto xp = find(root, x, 0, 0), yp = find(root, y, 0, 0);
        return xp.second == yp.second && xp.first != yp.first;
    }
};



class Solution
{
public:
    bool isCousins(TreeNode *root, int x, int y)
    {
        queue<pair<TreeNode *, int>> q;
        int lvl = 0, xp, xl, yp, yl;
        if (root)
            q.push({root, 0});
        while (!q.empty())
        {
            int k = q.size();
            while (k--)
            {
                auto [r, p] = q.front();
                q.pop();
                if(r->val == x)
                    xp = p, xl = lvl;
                if(r->val == y)
                    yp = p, yl = lvl;
                if (r->left)
                    q.push({r->left, r->val});
                if (r->right)
                    q.push({r->right, r->val});
            }
            lvl++;
        }
        return xp != yp && xl == yl;
    }
};

// @lc app=leetcode id=993 lang=cpp