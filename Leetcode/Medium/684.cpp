#include "../../headers.h"

// Union Find
class DSU
{
    vector<int> par, rank;
public:
    DSU(int n) : par(n), rank(n)
    {
        iota(begin(par), end(par), 0);
    }
    int find(int x)
    {
        if(x == par[x])
            return x;
        return par[x] = find(par[x]);
    }
    bool Union(int x, int y)
    {
        auto xp = find(x), yp = find(y);
        if(xp == yp)
            return false;
        if(rank[xp] > rank[yp])
            par[yp] = par[xp];
        else if(rank[xp] < rank[yp])
            par[xp] = par[yp];
        else
            par[xp] = yp, rank[yp]++;
        return true;
    }
};

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        DSU ds(edges.size() + 1);
        for(auto e: edges)
            if(!ds.Union(e[0], e[1]))
                return e;
        return {};
    }
};



// Time complexity - O(N)
// Space complexity - O(N)

class Solution
{
    unordered_set<int> cycle;
    int cycleStart = -1;
    void dfs(vector<vector<int>> &g, vector<int> &vis, int v, int p)
    {
        if (vis[v])
        {
            cycleStart = v;
            return;
        }
        vis[v] = 1;
        for (int c : g[v])
        {
            if (p == c)
                continue;
            if (cycle.empty())
                dfs(g, vis, c, v);
            if (cycleStart != -1)
                cycle.insert(v);
            if (v == cycleStart)
            {
                cycleStart = -1;
                return;
            }
        }
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        vector<vector<int>> g(edges.size() + 1);
        vector<int> vis(edges.size() + 1, 0);
        for (auto e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        dfs(g, vis, 1, -1);
        for (int i = edges.size() - 1; i >= 0; i--)
            if (cycle.count(edges[i][0]) && cycle.count(edges[i][1]))
                return edges[i];
        return {};
    }
};

// Time Complexity - O(N^2)
// Space Complexity - O(N) + recursive stack

class Solution
{
    bool dfs(vector<vector<int>> &g, vector<int> &vis, int v, int p)
    {
        if (vis[v])
            return true;
        vis[v] = 1;
        for (auto c : g[v])
            if (c != p && dfs(g, vis, c, v))
                return true;
        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        vector<vector<int>> g(edges.size() + 1);
        for (auto e : edges)
        {
            vector<int> vis(edges.size() + 1, 0);
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
            if (dfs(g, vis, e[0], -1))
                return e;
        }
        return {};
    }
};