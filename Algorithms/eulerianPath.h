#pragma once

#include <iostream>
#include <vector>

using namespace std;

class EulerianPath
{
public:
    vector<int> findPath(vector<vector<int>> &edges, int n)
    {
        int m = edges.size();
        vector<vector<int>> g(n);
        vector<int> deg(n, 0), path;
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            deg[e[1]]++;
        }
        
        deg[0]++;                           // for src outdeg - indeg = 0 or 1
        deg[n - 1]--;                       // for dest indeg - outdeg = 0 or 1
        for (int i = 0; i < n; i++)
            if (g[i].size() != deg[i])
                return {-1};

        auto dfs = [&](auto &&dfs, int u) -> void {
            while (g[u].size()) {
                int v = g[u].back();
                g[u].pop_back();
                dfs(dfs, v);
            }
            path.push_back(u);
        };
        dfs(dfs, 0);

        if (path.size() != m + 1)
            return {-1};

        reverse(path.begin(), path.end());
        return path;
    }
};