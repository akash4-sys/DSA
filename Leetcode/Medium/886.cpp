#include "../../headers.h"

class Solution
{
    bool dfs(vector<vector<int>> &adj, vector<int> &col, int u)
    {
        for (auto v : adj[u])
        {
            if(col[v] == -1)
            {
                col[v] = 1 - col[u];
                if(!dfs(adj, col, v))
                    return 0;
            }
            if(col[u] == col[v])
                return 0;
        }
        return 1;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n + 1);
        vector<int> col(n + 1, -1);
        for(auto e : edges)
            adj[e[0]].push_back(e[1]), adj[e[1]].push_back(e[0]);

        for (int i = 1; i <= n; i++)
            if(col[i] == -1 && !dfs(adj, col, i))
                return 0;
        return 1;
    }
};

// @lc app=leetcode id=886 lang=cpp