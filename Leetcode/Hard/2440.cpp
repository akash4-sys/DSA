#include "../../headers.h"

class Solution
{
    bool bfs(vector<int> v, vector<vector<int>> &g, vector<int> indegree, queue<int> q, int k)
    {
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int u = q.front();
                q.pop();
                if (v[u] > k)
                    return 0;
                for (auto c : g[u])
                {
                    v[c] += v[u] < k ? v[u] : 0;
                    if(--indegree[c] == 1)
                        q.push(c);
                }
            }
        }
        return 1;
    }

public:
    int componentValue(vector<int> &v, vector<vector<int>> &edges)
    {
        int n = v.size(), sum = accumulate(begin(v), end(v), 0);
        vector<vector<int>> g(n);
        vector<int> indegree(n, 0);
        queue<int> q;

        for (auto e : edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
            indegree[e[1]]++, indegree[e[0]]++;
        }

        for (int i = 0; i < n; i++)
            if (indegree[i] == 1)
                q.push(i);

        for (--n; n > 1; n--)
            if (sum % n == 0 && bfs(v, g, indegree, q, sum / n))
                return n - 1;
        return 0;
    }
};