#include "../../headers.h"

class Solution
{
public:
    vector<int> minOperationsQueries(int n, vector<vector<int>> &edges, vector<vector<int>> &qrs)
    {
        vector<vector<pair<int, int>>> g(n);
        for (auto e : edges) {
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }

        int m = log2(n) + 1;
        vector ancestor(m, vector<int>(n)), freq(n, vector<int>(27, 0));
        vector<int> depth(n, 0);

        function<void(int, int, int)> dfs = [&](int u, int par, int d) {
            ancestor[0][u] = par;
            depth[u] = d;
            for (auto &[c, w] : g[u])
                if (c != par)
                {
                    freq[c] = freq[u];
                    freq[c][w]++;
                    dfs(c, u, d + 1);
                }
        };
        dfs(0, 0, 0);

        for (int i = 1; i < m; i++)
            for (int j = 0; j < n; j++)
                ancestor[i][j] = ancestor[i - 1][ancestor[i - 1][j]];
        
        auto lca = [&](int u, int v) {
            if (depth[u] > depth[v])
                swap(u, v);

            for (int k = 0; (1 << k) <= depth[v] - depth[u]; k++)
                if ((1 << k) & depth[v] - depth[u])
                    v = ancestor[k][v];
            
            for (int k = m - 1; k >= 0; k--)
                if (ancestor[k][u] != ancestor[k][v])
                    u = ancestor[k][u], v = ancestor[k][v];
            
            return u == v ? u : ancestor[0][u];
        };

        vector<int> ans;
        for (auto &q : qrs)
        {
            int u = q[0], v = q[1], l = lca(u, v);
            int len = depth[u] + depth[v] - (2 * depth[l]), mx = 0;
            for (int w = 1; w <= 26; w++)
                mx = max(mx, freq[u][w] + freq[v][w] - (freq[l][w] * 2));
            ans.push_back(len - mx);
        }
        return ans;
    }
};



#define vv vector<vector<int>>
class Solution
{
    void dfs(vector<vv> &g, vector<int> &dp, vector<int> &freq, int u, int par, int len)
    {
        int mx = 0;
        for (int i = 1; i <= 26; i++)
            mx = max(mx, freq[i]);
        dp[u] = len - mx;

        for (auto &v : g[u])
            if (v[0] != par)
            {
                freq[v[1]]++;
                dfs(g, dp, freq, v[0], u, len + 1);
                freq[v[1]]--;
            }
    }

public:
    vector<int> minOperationsQueries(int n, vv &edges, vv &qrs)
    {
        vector<vv> g(n);
        vv dp(n, vector<int>(n));
        for (auto e : edges)
        {
            g[e[0]].push_back({e[1], e[2]});
            g[e[1]].push_back({e[0], e[2]});
        }

        vector<int> freq(27, 0), ans;
        for (int i = 0; i < n; i++)
            dfs(g, dp[i], freq, i, -1, 0);

        for (auto q : qrs)
            ans.push_back(dp[q[0]][q[1]]);
        return ans;
    }
};