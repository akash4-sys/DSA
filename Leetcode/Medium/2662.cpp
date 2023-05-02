#include "headers.h"

class Solution
{
public:
    int minimumCost(vector<int> &s, vector<int> &t, vector<vector<int>> &v)
    {
        using p = pair<int, int>;
        priority_queue<p, vector<p>, greater<p>> pq;

        int n = v.size();
        vector<int> dp(n, INT_MAX);
        for (int i = 0; i < n; i++)
            pq.push({abs(t[0] - v[i][2]) + abs(t[1] - v[i][3]), i});
        
        while (!pq.empty())
        {
            auto [w, u] = pq.top();
            pq.pop();
            if (dp[u] != INT_MAX)
                continue;

            dp[u] = min(dp[u], w);
            for (int c = 0; c < n; c++)
                if (u != c)
                {
                    int d = abs(v[u][0] - v[c][2]) + abs(v[u][1] - v[c][3]);
                    pq.push({w + d + v[u][4], c});
                }
        }

        int ans = abs(s[0] - t[0]) + abs(s[1] - t[1]);
        for (int i = 0; i < n; i++)
            ans = min(ans, abs(s[0] - v[i][0]) + abs(s[1] - v[i][1]) + v[i][4] + dp[i]);
        return ans;
    }
};




// trying to create a graph for dijkstra but didn't work

#define pb push_back
#define vec vector<int>
#define Dist(x1, y1, x2, y2) {abs(x2 - x1) + abs(y2 - y1)}

class Solution
{
public:
    int minimumCost(vector<int> &s, vector<int> &t, vector<vector<int>> &v)
    {
        map<vec, vector<vec>> adj;
        for (int i = 0; i < v.size(); i++)
        {
            adj[{s[0], s[1]}].pb({v[i][0], v[i][1], Dist(s[0], s[1], v[i][0], v[i][1])});
            adj[{v[i][0], v[i][1]}].pb({v[i][2], v[i][3], v[i][4]});
            adj[{v[i][0], v[i][1]}].pb({t[0], t[1], Dist(t[0], t[1], v[i][0], v[i][1])});

            for (int j = 0; j < v.size(); j++)
                if (i != j)
                    adj[{v[i][2], v[i][3]}].pb({v[j][0], v[j][1], Dist(v[i][2], v[i][3], v[j][0], v[j][1])});
        }

        map<vec, int> dist, vis;
        priority_queue<vec, vector<vec>, greater<vec>> pq;
        pq.push({0, s[0], s[1]});

        while (!pq.empty())
        {
            vec node = pq.top(), u = {node[1], node[2]};
            pq.pop();
            dist[u] = node[0];

            for (auto child : adj[u])
            {
                vec v = {child[0], child[1]};
                if (!dist.count(v))
                    dist[v] = INT_MAX;
                if (!vis.count(v) && dist[u] + child[2] < dist[v])
                    pq.push({dist[u] + child[2], child[0], child[1]});
            }
        }
        return dist[t];
    }
};