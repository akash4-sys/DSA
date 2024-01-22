#include "../../headers.h"

class Solution
{
public:
    vector<int> countOfPairs(int n, int x, int y)
    {
        if (x > y)
            swap(x, y);
        vector<int> ans(n, 0);
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                ans[min(abs(i - j), abs(i - x) + abs(y - j) + 1) - 1] += 2;
        return ans;
    }
};


class Solution
{
    unordered_map<int, vector<int>> g;
    int dfs(int dest, int u, vector<int> &vis)
    {
        if (u == dest)
            return 0;

        int res = 1000;
        for (int v : g[u])
            if (!vis[v])
            {
                vis[v] = 1;
                res = min(res, dfs(dest, v, vis) + 1);
                vis[v] = 0;
            }
        return res;
    }

public:
    vector<int> countOfPairs(int n, int x, int y)
    {
        for (int i = 1; i < n; i++)
            g[i].push_back(i + 1), g[i + 1].push_back(i);
        if (x != y)
            g[x].push_back(y), g[y].push_back(x);

        vector<int> ans(n, 0), vis(101, 0);
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
            {
                vis[i] = 1;
                ans[dfs(j, i, vis) - 1] += 2;
                vis[i] = 0;
            }
        return ans;
    }
};