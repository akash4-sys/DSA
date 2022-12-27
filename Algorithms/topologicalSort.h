#pragma once

#include <vector>
#include <queue>

using namespace std;

class TopologicalSort
{
public:
    void Tsort(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> g(n);
        vector<int> indegree(n);
        for (auto e : edges)
            g[e[1]].push_back(e[0]), indegree[e[0]]++;

        queue<int> q;
        for (int i = 0; i < n; i++)
            if (!indegree[i])
                q.push(i);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (auto c : g[v])
                if (--indegree[c] == 0)
                    q.push(c);
        }
    }
};