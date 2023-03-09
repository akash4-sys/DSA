#include "../../headers.h"

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
    map<vector<int>, int> mp;
    int dfs(vector<vector<int>> &g, int par, int u)
    {
        int res = 0;
        for (int v : g[u])
        {
            if (par == v)
                continue;
            res += dfs(g, u, v) + mp.count({u, v});
        }
        return res;
    }

    int dfs(vector<vector<int>> &g, int k, int par, int u, int res)
    {
        int ans = res >= k;
        for (int v : g[u])
        {
            if (par == v)
                continue;
            ans += dfs(g, k, u, v, res - mp.count({u, v}) + mp.count({v, u}));
        }
        return ans;
    }

public:
    int rootCount(vector<vector<int>> &edges, vector<vector<int>> &guess, int k)
    {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for (auto &e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);

        for (auto &v : guess)
            mp[v] = 1;
        return dfs(g, k, -1, 0, dfs(g, -1, 0));
    }
};

// Time Complexity - O(N^2)
// Space Complexity - O(N^2)

class Solution
{
    map<vector<int>, int> mp;
    int dfs(vector<vector<int>> &g, int par, int u)
    {
        int res = 0;
        for (int v : g[u])
        {
            if (par == v)
                continue;
            res += dfs(g, u, v) + mp.count({u, v});
        }
        return res;
    }

public:
    int rootCount(vector<vector<int>> &edges, vector<vector<int>> &guess, int k)
    {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for (auto &e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);

        for (auto &v : guess)
            mp[v] = 1;

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += dfs(g, -1, i) >= k;
        return ans;
    }
};