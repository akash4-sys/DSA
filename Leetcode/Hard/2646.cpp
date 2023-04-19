#include "headers.h"

class Solution
{
    vector<vector<int>> g;
    vector<int> cnt;
    bool path(int par, int u, int dest)
    {
        if (u == dest)
            return ++cnt[u];
        for (int v : g[u])
            if (v != par && path(u, v, dest))
                return ++cnt[u];
        return 0;
    }

    pair<int, int> dfs(vector<int> &p, int u, int par)
    {
        int val = p[u] * cnt[u], half = val / 2;
        for (int v : g[u])
            if (v != par)
            {
                auto [cval, chalf] = dfs(p, v, u);
                val += min(cval, chalf);
                half += cval;
            }
        return {val, half};
    }

public:
    int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &p, vector<vector<int>> &trips)
    {
        g = vector<vector<int>>(n);
        cnt = vector<int>(n, 0);
        for (auto e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);

        for (auto t : trips)
            path(-1, t[0], t[1]);
        auto [val, half] = dfs(p, 0, -1);
        return min(val, half);
    }
};