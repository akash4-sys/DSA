#include "../../headers.h"

class DSU
{
    vector<int> parent;
public:
    DSU(int n) : parent(n)
    {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u)
    {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    }

    void Union(int u, int v)
    {
        int up = find(u), vp = find(v);
        if (up != vp)
            parent[up] = vp;
    }
};

class Solution
{
public:
    int numberOfGoodPaths(vector<int>& v, vector<vector<int>>& edges) 
    {
        map<int, vector<int>> mp;
        for (int i = 0; i < v.size(); i++)
            mp[v[i]].push_back(i);
        
        vector<vector<int>> g(v.size());
        for (auto e : edges)
            if (v[e[0]] >= v[e[1]])
                g[e[0]].push_back(e[1]);
            else
                g[e[1]].push_back(e[0]);
        
        DSU dsu(v.size());
        int ans = 0;
        for (auto &[val, nodes]: mp)
        {
            for (int u : nodes)
                for (int v : g[u])
                    dsu.Union(u, v);
            
            unordered_map<int, int> grp;
            for (int u : nodes)
                grp[dsu.find(u)]++;

            for (auto &[_, c] : grp)
                ans += (c * (c - 1) / 2);
        }
        return ans + v.size();
    }
};

// TLE
class Solution
{
    int dfs(vector<int> &val, vector<vector<int>> &g, int st, int par, int u)
    {
        int res = 0;
        for (int v : g[u])
        {
            if (par == v || val[v] > st)
                continue;
            res += (val[v] == st) + dfs(val, g, st, u, v);
        }
        return res;
    }

public:
    int numberOfGoodPaths(vector<int> &v, vector<vector<int>> &edges)
    {
        vector<vector<int>> g(v.size());
        for (auto &e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);

        int ans = 0;
        for (int i = 0; i < v.size(); i++)
            ans += dfs(v, g, v[i], -1, i);
        return (ans / 2) + v.size();
    }
};