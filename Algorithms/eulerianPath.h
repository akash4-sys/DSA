#pragma once

#include <iostream>
#include <vector>

using namespace std;

class EulerianPath
{
    int startNode = -1;
    vector<int> indegree, outdegree, path;
    vector<vector<int>> adj;

    bool hasEulerianPath(int n)
    {
        int start = 0, end = 0;
        for (int i = 0; i < n; i++)
        {
            if (abs(outdegree[i] - indegree[i]) > 1)
                return 0;
            if (outdegree[i] - indegree[i] == 1)
                startNode = i, start++;
            end += indegree[i] - outdegree[i] == 1;
        }
        return (!start && !end) || (start == 1 && end == 1);
    }

    void dfs(int u)
    {
        while (outdegree[u])
            dfs(adj[u][--outdegree[u]]);
        path.insert(path.begin(), u);
    }

public:
    vector<int> eulerianPath(vector<vector<int>> &edges, int n)
    {
        adj = vector<vector<int>>(n);
        indegree = outdegree = vector<int>(n);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
            outdegree[e[0]]++;
            startNode = e[0];
        }

        if (!edges.size() || !hasEulerianPath(n))
            return {};

        dfs(startNode);
        return path;
    }
};