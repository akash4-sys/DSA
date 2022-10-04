#include "../../headers.h"
// @lc app=leetcode id=1334 lang=cpp

typedef pair<int, int> p;
class Solution
{
    vector<int> city;
    void dijkstra(vector<vector<p>> &g, int src, int n, int maxD)
    {
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> dist(n, INT_MAX), vis(n, 0);

        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty())
        {
            auto [d, v] = pq.top();
            pq.pop();
            vis[v] = 1;
            for (auto &[c, cd] : g[v])
                if (!vis[c] && d + cd < dist[c] && d + cd <= maxD)
                    dist[c] = d + cd, pq.push({dist[c], c});
        }

        int cnt = 0;
        for (auto x : dist)
            cnt += (x != INT_MAX);
        city[src] = cnt;
    }

public:
    int findTheCity(int n, vector<vector<int>> &edges, int maxD)
    {
        city = vector<int>(n);
        vector<vector<p>> g(n);
        for (auto e : edges)
            g[e[0]].push_back({e[1], e[2]}), g[e[1]].push_back({e[0], e[2]});

        for (int i = 0; i < n; i++)
            dijkstra(g, i, n, maxD);

        int ans = 0, m = INT_MAX;
        for (int i = 0; i < n; i++)
            if (m >= city[i])
                ans = i, m = city[i];
        return ans;
    }
};




//  Floyd Warshall

class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int maxD)
    {
        vector<vector<int>> g(n, vector<int>(n, 10001));
        int ans = 0, smallest = n;
        for(auto &e: edges)
            g[e[0]][e[1]] = g[e[1]][e[0]] = e[2];
        
        for(int i = 0; i < n; i++)
            g[i][i] = 0;
        
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
        
        for(int i = 0; i < n; i++)
        {
            int c = 0;
            for(int j = 0; j < n; j++)
                if(g[i][j] <= maxD)
                    ++c;
            if(c <= smallest)
                ans = i, smallest = c;
        }
        return ans;
    }
};
