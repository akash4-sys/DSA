#include "../../headers.h"

class Solution
{
    vector<vector<int>> g, rg;
    map<pair<int, int>, int> dp;

    int dfs(int u, int par)
    {
        if (dp.count({u, par}))
            return dp[{u, par}];
        
        int res = 0;
        for (int v : g[u])
            if (v != par)
                res += dfs(v, u);
        for (int v : rg[u])
            if (v != par)
                res += dfs(v, u) + 1;
        return dp[{u, par}] = res;
    }

public:
    vector<int> minEdgeReversals(int n, vector<vector<int>> &edges)
    {
        dp.clear();
        g = rg = vector<vector<int>>(n);
        for (auto &e : edges)
        {
            g[e[0]].push_back(e[1]);
            rg[e[1]].push_back(e[0]);
        }

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++)
            ans[i] = dfs(i, -1);
        return ans;
    }
};