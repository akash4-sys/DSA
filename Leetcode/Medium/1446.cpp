#include "../../headers.h"

class Solution
{
public:
    int minReorder(int n, vector<vector<int>> &edge)
    {
        int ans = 0;
        vector<vector<int>> g(n);
        for (auto e : edge)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(-e[0]);
        queue<int> q;
        vector<int> vis(n, 0);
        q.push(0);
        vis[0] = 1;

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int c : g[v])
                if (!vis[abs(c)])
                    ans += c > 0, q.push(abs(c)), vis[abs(c)] = 1;
        }
        return ans;
    }
};



class Solution
{
    int ans = 0;
    void dfs(vector<vector<int>>& g, vector<int> vis, int v)
    {
        if(vis[v])
            return;
        vis[v] = 1;
        for(int c: g[v])
            if(!vis[abs(c)])
                ans += c > 0, dfs(g, vis, abs(c));
        return;
    }

public:
    int minReorder(int n, vector<vector<int>> &edge)
    {
        vector<vector<int>> g(n);
        for (auto e : edge)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(-e[0]);
        vector<int> vis(n, 0);
        dfs(g, vis, 0);
        return ans;
    }
};