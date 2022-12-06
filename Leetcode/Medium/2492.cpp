#include "headers.h"

// Amazing
class Solution
{
public:
    int minScore(int N, vector<vector<int>> &edges)
    {
        int ans = INT_MAX;
        for (auto e : edges)
            ans = min(ans, e[2]);
        return ans;
    }
};


// Intutive
// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution
{
public:
    int minScore(int n, vector<vector<int>> &edges)
    {
        using p = pair<int, int>;
        vector<vector<p>> g(n + 1);
        vector<int> vis(n + 1, 0);
        for (auto e : edges)
            g[e[0]].push_back({e[1], e[2]}), g[e[1]].push_back({e[0], e[2]});
        queue<int> q;
        q.push(1);
        int ans = INT_MAX;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (vis[u])
                continue;
            vis[u] = 1;
            for (auto &[v, w] : g[u])
                ans = min(ans, w), q.push(v);
        }
        return ans;
    }
};