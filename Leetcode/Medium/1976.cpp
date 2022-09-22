#include "../../headers.h"

typedef long long ll;

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        using p = pair<int, int>;
        vector<vector<p>> g(n);
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> dist(n, 0), cnt(n, 1);
        int mod = 1e9 + 7;

        for (auto e : roads)
            g[e[0]].push_back({e[1], e[2]}), g[e[1]].push_back({e[0], e[2]});

        pq.push({0, 0});
        dist[0] = 0;

        while (!pq.empty())
        {
            auto [w, v] = pq.top();
            pq.pop();
            for (auto [c, cost] : g[v])
                if (!dist[c] || dist[c] >= w + cost)
                    if(dist[c] == cost + w)
                       cnt[c] = (cnt[c] + cnt[v]) % mod;
                    else
                        dist[c] = cost + w, cnt[c] = cnt[v], pq.push({dist[c], c});
        }
        return cnt[n - 1];
    }
};