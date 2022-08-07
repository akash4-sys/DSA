#include "headers.h"


// Not MLE
class Solution
{
public:
    int dfs(int i, vector<int> &vis, vector<int> adj[])
    {
        if (vis[i])
            return 0;
        vis[i] = 1;
        int res = 0;
        for (auto edge : adj[i])
            if (!vis[edge])
                res += dfs(edge, vis, adj);
        return res + 1;
    }

    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &res)
    {
        vector<int> vis(n, 0);
        vector<int> adj[n];
        for (auto x : res)
            vis[x] = 1;
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]); 
            adj[e[1]].push_back(e[0]);
        }
        return dfs(0, vis, adj);
    }
};




// MLE
class Solution
{
public:
    int c = 0;
    void dfs(vector<vector<int>> &adj, vector<int> vis, int i)
    {
        if (vis[i])
            return;
        vis[i] = 1;
        c++;
        for (auto e : adj[i])
            if (!vis[e])
                dfs(adj, vis, e);
        return;
    }

    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &res)
    {
        vector<vector<int>> adj(n);
        for (auto e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        for (auto x : res)
            vis[x] = 1;

        dfs(adj, vis, 0);
        return c;
    }
};