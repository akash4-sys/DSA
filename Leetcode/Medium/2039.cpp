#include "../../headers.h"

class Solution
{
public:
    int networkBecomesIdle(vector<vector<int>> &edges, vector<int> &p)
    {
        vector<vector<int>> g(p.size());
        queue<int> q;
        vector<int> time(p.size(), -1);

        for (auto e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);

        q.push(0);
        time[0] = 0;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (auto c : g[v])
                if (time[c] == -1)
                    time[c] = time[v] + 1, q.push(c);
        }

        int ans = 0;
        for (int i = 1; i < p.size(); i++)
        {
            int extraPayload = ((time[i] * 2 - 1) / p[i]) * p[i];
            int x = extraPayload + (time[i] * 2);
            ans = max(ans, x);
        }
        return ans + 1;
    }
};