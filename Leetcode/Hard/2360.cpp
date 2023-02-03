#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
public:
    int longestCycle(vector<int> &g)
    {
        int ans = -1;
        vector<pair<int, int>> dp(g.size(), {-1, -1});
        for (int i = 0; i < g.size(); i++)
            for (int u = i, len = 0; u != -1; u = g[u])
            {
                auto [clen, st] = dp[u];
                if (st != -1)
                {
                    ans = max(ans, st == i ? len - clen : -1);
                    break;
                }
                dp[u] = {len++, i};
            }
        return ans;
    }
};


// Time Complexity - O(N^2)
// Space Complexity - O(N)
class Solution
{
    int dfs(vector<int> &edges, vector<int> &vis, int st, int u, int len)
    {
        if (u == -1)
            return -1;
        if (vis[u])
            return st == u ? len : -1;
        vis[u] = 1;
        return dfs(edges, vis, st, edges[u], len + 1);
    }

public:
    int longestCycle(vector<int> &edges)
    {
        int ans = -1;
        for (int i = 0; i < edges.size(); i++)
        {
            vector<int> vis(edges.size(), 0);
            ans = max(ans, dfs(edges, vis, i, i, 0));
        }
        return ans;
    }
};