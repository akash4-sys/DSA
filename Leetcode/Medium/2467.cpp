#include "../../headers.h"

class Solution
{
    vector<int> par, dis;
    void dfs(vector<vector<int>> &g, int u, int p = 0, int d = 0)
    {
        dis[u] = d;
        par[u] = p;
        for(int v: g[u])
            if(v != p)
                dfs(g, v, u, d + 1);
    }

    int dfs(vector<vector<int>> &g, vector<int> &v, int u, int p = 0)
    {
        int ans = v[u], m = INT_MIN;
        for(int c: g[u])
            if(p != c)
                m = max(m, dfs(g, v, c, u));
        return m == INT_MIN ? ans : m + ans;
    }

public:
    int mostProfitablePath(vector<vector<int>> &edges, int b, vector<int> &v)
    {
        vector<vector<int>> g(v.size());
        dis = par = vector<int>(v.size());
        for(auto &e: edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        
        dfs(g, 0);
        int i = 0;
        while(b)
        {
            if(dis[b] > i)
                v[b] = 0;
            else if(dis[b] == i)
                v[b] /= 2;
            b = par[b];
            i++;
        }
        return dfs(g, v, 0);
    }
};