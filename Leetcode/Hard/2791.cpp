#include "headers.h"

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution
{
    long long dfs(vector<vector<int>> &g, string &s, unordered_map<int, int> &dp, int u, int mask)
    {
        long long res = 0;
        if (u)
        {
            mask ^= 1 << (s[u] - 'a');
            for (int i = 1 << 25; i; i >>= 1)
                res += dp.count(mask ^ i) ? dp[mask ^ i] : 0;
            res += dp[mask]++;
        }

        for (auto v : g[u])
            res += dfs(g, s, dp, v, mask);
        return res;
    }

public:
    long long countPalindromePaths(vector<int> &par, string s)
    {
        unordered_map<int, int> dp = {{0, 1}};
        vector<vector<int>> g(par.size());
        for (int i = 1; i < par.size(); i++)
            g[par[i]].push_back(i);
        return dfs(g, s, dp, 0, 0);
    }
};


// Time Complexity - O(N^2)
// Space Complexity - O(N^2)

class Solution
{
    long long rec(vector<vector<pair<int, char>>> &g, vector<int> &vis, int st, int u, int mask)
    {
        vis[u] = 1;
        long long res = (__builtin_popcount(mask) <= 1 && st < u);
        for (auto [v, c] : g[u])
            if (!vis[v])
                res += rec(g, vis, st, v, mask ^ (1 << (c - 'a')));
        return res;
    }

public:
    long long countPalindromePaths(vector<int> &v, string s)
    {
        vector<vector<pair<int, char>>> adj(v.size());
        for (int i = 1; i < v.size(); i++)
            adj[v[i]].push_back({i, s[i]}), adj[i].push_back({v[i], s[i]});
        
        long long ans = 0;
        for (int i = 0; i < v.size(); i++) {
            vector<int> vis(v.size(), 0);
            ans += rec(adj, vis, i, i, 0);
        }
        return ans;
    }
};