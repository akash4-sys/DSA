#include "../../headers.h"

class UnionFind
{
    vector<int> par;
public:
    UnionFind(int n) : par(n)
    {
        iota(par.begin(), par.end(), 0);
    }

    int find(int i)
    {
        if (par[i] != i)
            par[i] = find(par[i]);
        return par[i];
    }

    void connect(int i, int j)
    {
        int p1 = find(i), p2 = find(j);
        if (p1 != p2)
            par[p1] = par[p2];
    }
};

class Solution
{
public:
    int numberOfGoodPaths(vector<int> &v, vector<vector<int>> &edges)
    {
        int n = v.size();
        map<int, vector<int>> mp;
        vector<vector<int>> g(n);
        for (int i = 0; i < n; i++)
            mp[v[i]].push_back(i);

        for (auto &e : edges)
            if (v[e[0]] >= v[e[1]])
                g[e[0]].push_back(e[1]); 
            else
                g[e[1]].push_back(e[0]);
        
        int ans = 0;
        UnionFind uf(n);
        for (auto &[val, nodes]: mp)
        {
            for (int u : nodes)
                for (int v : g[u])
                    uf.connect(u, v);
            
            unordered_map<int, int> grp;
            for (int u : nodes)
                grp[uf.find(u)]++;
            ans += nodes.size();
            for (auto &[_, c]: grp)
                ans += (c * (c - 1) / 2);
        }
        return ans;
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