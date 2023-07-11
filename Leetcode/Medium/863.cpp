#include "../../headers.h"
#include "../../treestructure.h"

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
    unordered_map<TreeNode *, TreeNode *> par;
    unordered_map<TreeNode *, int> vis;
    void findPar(TreeNode *root, TreeNode *p)
    {
        if (!root)
            return;
        par[root] = p;
        findPar(root->left, root);
        findPar(root->right, root);
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *t, int k)
    {
        findPar(root, nullptr);
        vector<int> ans;
        queue<TreeNode *> q{{t}};

        for (int lvl = 0; !q.empty() && lvl <= k; lvl++)
            for (int sz = q.size(); sz; sz--)
            {
                auto r = q.front();
                q.pop();
                vis[r] = 1;
                if (lvl == k)
                    ans.push_back(r->val);
                if(r->left && !vis[r->left])
                    q.push(r->left);
                if(r->right && !vis[r->right])
                    q.push(r->right);
                if(par[r] && !vis[par[r]])
                    q.push(par[r]);
            }
        return ans;
    }
};

// Time Complexity - O(N)
// Space Complxity - O(N) - Direct Modification to save space

class Solution
{
    vector<int> ans;
    unordered_map<TreeNode *, TreeNode *> par;

    void findPar(TreeNode *root, TreeNode *p)
    {
        if (!root)
            return;
        par[root] = p;
        findPar(root->left, root);
        findPar(root->right, root);
    }

    void dfs(TreeNode *root, int k)
    {
        if (!root || root->val == -1)
            return;
        if (!k)
        {
            ans.push_back(root->val);
            return;
        }
        root->val = -1;
        dfs(par[root], k - 1);
        dfs(root->left, k - 1);
        dfs(root->right, k - 1);
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *tar, int k)
    {
        findPar(root, NULL);
        dfs(tar, k);
        return ans;
    }
};