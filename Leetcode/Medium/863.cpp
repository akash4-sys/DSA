#include "../../headers.h"
#include "../../treestructure.h"

class Solution
{
    unordered_map<TreeNode *, TreeNode *> par;
    unordered_map<TreeNode *, int> vis;
    void findParents(TreeNode *root, TreeNode *p)
    {
        if (!root)
            return;
        par[root] = p;
        findParents(root->left, root);
        findParents(root->right, root);
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *t, int k)
    {
        findParents(root, nullptr);
        vector<int> ans;
        queue<TreeNode *> q;
        int lvl = 0;
        q.push(t);
        vis[t] = 1;

        while(!q.empty())
        {
            if(lvl++ == k) break;
            int sz = q.size();
            while(sz--)
            {
                auto r = q.front();
                q.pop();
                if(r->left && !vis[r->left])
                    q.push(r->left), vis[r->left] = 1;
                if(r->right && !vis[r->right])
                    q.push(r->right), vis[r->right] = 1;
                if(par[r] && !vis[par[r]])
                    q.push(par[r]), vis[par[r]] = 1;
            }
        }

        while(!q.empty())
            ans.push_back(q.front()->val), q.pop();
        return ans;
    }
};