#include "../../headers.h"

class Solution
{
    long long dfs(vector<vector<int>> &g, vector<int> &val, int u, int par)
    {
        long long res = 0;
        for (int &v : g[u])
            if (v != par)
                res += dfs(g, val, v, u);
        return res ? min(res, (long long)val[u]) : val[u];
    }

public:
    long long maximumScoreAfterOperations(vector<vector<int>> &edges, vector<int> &v)
    {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for (auto &e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        return accumulate(v.begin(), v.end(), 0LL) - dfs(g, v, 0, -1);
    }
};