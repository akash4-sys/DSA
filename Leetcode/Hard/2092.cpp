#include "../../headers.h"

class Solution
{
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &edges, int fp)
    {
        vector<int> vis(n, 0), ans;
        vector<vector<pair<int, int>>> g(n);
        for (auto &e : edges)
            g[e[0]].push_back({e[2], e[1]}), g[e[1]].push_back({e[2], e[0]});

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        pq.push({0, fp});
        
        vis[0] = vis[fp] = 1;
        while (!pq.empty())
        {
            auto [time, u] = pq.top();
            pq.pop();
            vis[u] = 1;
            for (auto &[ctime, c] : g[u])
                if (!vis[c] && time <= ctime)
                    pq.push({ctime, c});
        }

        for (int i = 0; i < n; i++)
            if (vis[i])
                ans.push_back(i);
        return ans;
    }
};