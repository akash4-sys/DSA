#include "../../headers.h"
#include "../../treestructure.h"

// Time Complexity - O(N)
// Space Complexity - O(H)
class Solution
{
    TreeNode *lca;
    int deepest = 0;
    int level(TreeNode *node, int depth)
    {
        deepest = max(deepest, depth);
        if (!node)
            return depth;
        int left = level(node->left, depth + 1);
        int right = level(node->right, depth + 1);
        if (left == deepest && right == deepest)
            lca = node;
        return max(left, right);
    }

public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        level(root, 0);
        return lca;
    }
};



// Time Complexity - O(N)
// Space Complexity - O(H)
class Solution
{
    vector<TreeNode *> levelOrder(TreeNode *root)
    {
        vector<TreeNode *> leafs;
        queue<TreeNode *> q;
        if (root)
            q.push(root);
        while (!q.empty())
        {
            int k = q.size();
            TreeNode *last;
            leafs = {};
            while (k--)
            {
                auto r = q.front();
                q.pop();
                if (leafs.empty())
                    leafs.push_back(r);
                last = r;
                if (r->left)
                    q.push(r->left);
                if (r->right)
                    q.push(r->right);
            }
            leafs.push_back(last);
        }
        return leafs;
    }

    TreeNode *lca(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || root == p || root == q)
            return root;
        auto l = lca(root->left, p, q);
        auto r = lca(root->right, p, q);
        if (l && r)
            return root;
        return l ? l : r;
    }

public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        vector<TreeNode *> leafs = levelOrder(root);
        return lca(root, leafs[0], leafs[1]);
    }
};