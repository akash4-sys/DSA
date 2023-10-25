#include "../../headers.h"

class Solution
{
public:
    int minimumTime(int n, vector<vector<int>> &edges, vector<int> &time)
    {
        vector<vector<int>> g(n);
        vector<int> indegree(n), t(n);
        for (auto e : edges)
            g[e[0] - 1].push_back(e[1] - 1), indegree[e[1] - 1]++;

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (!indegree[i])
                q.push(i), t[i] = time[i];

        int ans = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : g[u])
            {
                t[v] = max(t[v], time[v] + t[u]);
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }
        return *max_element(t.begin(), t.end());
    }
};