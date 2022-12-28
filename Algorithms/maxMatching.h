#pragma once

#include <vector>

using namespace std;

// @ For Bipartite graph only
// @ In a bipartite graph consider two sets n and m where u have to make sure that maximum possible nodes of set m gets paired with set n.

class maxMatching
{
    bool dfs(vector<vector<int>> &graph, vector<int> &match, vector<int> &vis, int u, int n)
    {
        for (int v = 0; v < n; v++)
            if (graph[u][v] && !vis[v])
            {
                vis[v] = 1;
                if (match[v] < 0 || dfs(graph, match, vis, match[v], n))
                {
                    match[v] = u;
                    return 1;
                }
            }
        return 0;
    }

public:
    int maxMatch(vector<vector<int>> &graph, int n, int m)
    {
        vector<int> match(n, -1);
        int maxMatched = 0;
        for (int u = 0; u < m; u++)
        {
            vector<int> vis(n, 0);
            maxMatched += dfs(graph, match, vis, u, n);
        }
        return maxMatched;
    }
};