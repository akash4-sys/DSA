#pragma once

#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// ! somwhere something is wrong lvl 1 error

class MaxFlow
{
    long delta = 0;
    void generateGraph(vector<vector<int>> &edges, vector<vector<int>> &graph)
    {
        for (auto e : edges)
        {
            graph[e[0]][e[1]] += e[2];
            graph[e[1]][e[0]] += e[2];
            delta = max(delta, (long)e[2]);
        }
    }

    void augmentEdges(vector<vector<int>> &graph, vector<int> &parent, int src, int dest, long minFlow)
    {
        for (int u = dest; u != src; u = parent[u])
        {
            graph[parent[u]][u] -= minFlow;
            graph[u][parent[u]] += minFlow;
        }
    }

    long dfs(vector<vector<int>> &graph, vector<int> &vis, vector<int> &parent, int u, int src, int dest, long flow)
    {
        if (u == dest)
            return flow;
        
        vis[u] = 1;
        for (int v = 0; v < graph.size(); v++)
            if (!vis[v] && graph[u][v] >= delta)
            {
                parent[v] = u;
                long minFlow = dfs(graph, vis, parent, v, src, dest, min((long)graph[u][v], flow));
                if (minFlow > 0)
                {
                    augmentEdges(graph, parent, src, dest, minFlow);
                    return minFlow;
                }
            }
        return 0;
    }

public:
    int maxFlow(vector<vector<int>> &edges, int n, int src, int dest)
    {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        generateGraph(edges, graph);

        // delta at largest power of 2 <= maxCap
        delta = (long)pow(2, (int)floor(log(delta) / log(2)));

        int max_flow = 0;
        vector<int> vis(n, 0), parent(n, -1);
        for (; delta; delta /= 2)
        {
            for (long flow = LLONG_MAX; flow > 0;)
            {
                vis = vector<int>(n, 0);
                flow = dfs(graph, vis, parent, src, src, dest, INT_MAX);
                max_flow += flow;
            }
        }
        return max_flow;
    }
};