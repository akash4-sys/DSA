#include "../../headers.h"

class Solution
{
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &v, int k)
    {
        vector<vector<int>> g(n);
        for (auto e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        
        vector<int> cnt(n);
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            cnt[i] = g[i].size();
            if (g[i].size() < 2)
                q.push(i);
        }
        
        int ans = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            cnt[u]--;
            ans += v[u] % k == 0;
            for (int c : g[u])
                if (cnt[c])
                {
                    v[c] += v[u] % k;
                    if (--cnt[c] == 1)
                        q.push(c);
                }
        }
        return ans;
    }
};