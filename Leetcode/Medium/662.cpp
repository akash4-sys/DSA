#include "../../headers.h"
#include "../../treestructure.h"

// width of binary tree

// Directly modifying the tree

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        queue<TreeNode *> q;
        if (root)
            q.push(root);
        while (!q.empty())
        {
            int k = q.size(), st = q.front()->val;
            ans = max(ans, q.back()->val - st + 1);
            while (k--)
            {
                auto r = q.front();
                q.pop();
                long long i = (long long)(r->val - st) * 2;
                if (r->left)
                    r->left->val = i + 1, q.push(r->left);
                if (r->right)
                    r->right->val = i + 2, q.push(r->right);
            }
        }
        return ans;
    }
};


// without modifying the tree

class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        int ans = 0;
        queue<pair<TreeNode *, int>> q;
        if (root)
            q.push({root, 0});
        while (!q.empty())
        {
            int k = q.size(), st = q.front().second;
            ans = max(ans, q.back().second - st + 1);
            while (k--)
            {
                auto [r, i] = q.front();
                q.pop();
                i -= st;        // to prevent integer overflow
                if (r->left)
                    q.push({r->left, ((long long)2 * i) + 1});
                if (r->right)
                    q.push({r->right, ((long long)2 * i) + 2});
            }
        }
        return ans;
    }
};

// @lc app=leetcode id=662 lang=cpp