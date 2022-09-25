#include "../../headers.h"
// @lc app=leetcode id=1786 lang=cpp

typedef pair<int, int> p;
class Solution
{
public:
    int countRestrictedPaths(int n, vector<vector<int>> &edges)
    {
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<p>> g(n + 1);
        vector<long> cnt(n + 1, 0), dist(n + 1, INT_MAX);
        int mod = 1e9 + 7;

        for (auto e : edges)
            g[e[0]].push_back({e[1], e[2]}), g[e[1]].push_back({e[0], e[2]});
        pq.push({0, n});
        dist[n] = 0;
        dist[0] = -1;
        cnt[n] = 1;

        while (!pq.empty())
        {
            auto [w, v] = pq.top();
            pq.pop();
            if(w > dist[v])
                continue;
            for (auto &[c, cw] : g[v])
            {
                if(dist[c] > cw + w)
                    dist[c] = cw + w, pq.push({dist[c], c});
                if(w > dist[c])
                    cnt[v] = (cnt[c] + cnt[v]) % mod;
            }
        }
        return cnt[1];
    }
};

