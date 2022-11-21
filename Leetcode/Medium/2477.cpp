#include "headers.h"

class Solution
{
    long long ans = 0, k;
    int dfs(vector<vector<int>> &g, int u, int prev, int d = 1)
    {
        for(int v: g[u])
            if(v != prev)
                d += dfs(g, v, u);
        if(u != 0)
            ans += (d + k - 1) / k;
        return d;
    }
public:
    long long minimumFuelCost(vector<vector<int>> &edges, int seats)
    {
        vector<vector<int>> g(edges.size() + 1);
        for(auto e: edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        k = seats;
        dfs(g, 0, 0);
        return ans;
    }
};