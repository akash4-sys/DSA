#include "../../headers.h"

#define ll long long
#define p pair<int, int>

class Solution
{
    vector<ll> minDist(vector<vector<p>> &adj, int src)
    {
        int n = 26;
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<ll> vis(n, 0), dist(n, INT_MAX);

        pq.push({0, src});
        dist[src] = 0;
        while (!pq.empty())
        {
            auto [w, u] = pq.top();
            pq.pop();
            vis[u] = 1;
            for (auto [v, wt] : adj[u])
                if (!vis[v] && dist[u] + wt < dist[v])
                    dist[v] = dist[u] + wt, pq.push({dist[v], v});   
        }
        return dist;
    }

public:
    ll minimumCost(string s, string t, vector<char> &o, vector<char> &cg, vector<int> &cost)
    {
        vector<vector<p>> g(26);
        for (int i = 0; i < o.size(); i++)
            g[o[i] - 'a'].push_back({cg[i] - 'a', cost[i]});
        
        vector<vector<ll>> dist;
        for (int i = 0; i < 26; i++)
            dist.push_back(minDist(g, i));

        ll ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (dist[s[i] - 'a'][t[i] - 'a'] == INT_MAX)
                return -1;
            ans += dist[s[i] - 'a'][t[i] - 'a'];
        }
        return ans;
    }
};