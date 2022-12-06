#include "../../headers.h"

class Solution
{
    void minDistance(vector<vector<int>> &g, vector<vector<int>> &dist, int s)
    {
        dist[s][s] = 1;
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(int v: g[u])
                if(dist[s][v] > dist[s][u] + 1)
                    dist[s][v] = dist[s][u] + 1, q.push(v);
        }
    }

    bool isBipartite(vector<vector<int>> &g, vector<int> &color, vector<int> &conn, int u, int c = 1)
    {
        color[u] = c;
        conn.push_back(u);
        for(int v: g[u])
            if((!color[v] && !isBipartite(g, color, conn, v, 3 - c)) || color[v] == c)
                return 0;
        return 1;
    }

public:
    int magnificentSets(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> g(n + 1), dist(n + 1, vector<int>(n + 1, INT_MAX));
        vector<int> color(n + 1, 0);
        for(auto e: edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        
        for(int i = 1; i <= n; i++)
            minDistance(g, dist, i);
        
        int ans = 0, in = 0;
        for(int i = 1; i <= n; i++)
        {
            if(color[i])
                continue;
            vector<int> conn;
            in++;
            if(!isBipartite(g, color, conn, i))
                return -1;
            int maxD = 0;
            for(int u: conn)
                for(int v: conn)
                    maxD = max(maxD, dist[u][v]);
            ans += maxD;
        }
        return ans;
    }
};


// @lc app=leetcode id=2493 lang=cppX