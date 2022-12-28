#pragma once

#include <vector>
#include <queue>

using namespace std;

// @ Ford-Fulkerson algorithm using edmond karp technique
//  Time Complexity - O(E^2V)
//  Space Complexity - O(V^2)

class MaxFlow
{
    void generateGraph(vector<vector<int>> &edges, vector<vector<int>> &graph)
    {
        for (auto e : edges)
        {
            graph[e[0]][e[1]] += e[2];
            graph[e[1]][e[0]] += e[2];
        }
    }

    void dfs(vector<vector<int>> &graph, vector<int> &vis, int u)
    {
        vis[u] = 1;
        for (int v = 0; v < graph.size(); v++)
            if (!vis[v] && graph[u][v])
                dfs(graph, vis, v);
    }

    vector<int> minCutEdges(vector<vector<int>> &graph, vector<vector<int>> &orgGraph, int n, int src)
    {
        vector<int> vis(n, 0), ans;
        dfs(graph, vis, src);

        for (int u = 0; u < graph.size(); u++)
            for (int v = 0; v < graph.size(); v++)
                if (vis[u] && !vis[v] && orgGraph[u][v])
                    ans.push_back(u), ans.push_back(v);
        return ans;
    }

    bool bfs(vector<vector<int>> &graph, vector<int> &parent, int n, int src, int dest)
    {
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(src);
        parent[src] = -1;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            if (u == dest)
                return 1;
            vis[u] = 1;
            for (int v = 0; v < n; v++)
                if (!vis[v] && graph[u][v] > 0)
                    parent[v] = u, q.push(v);
        }
        return 0;
    }
    

public:
    int maxFlow(vector<vector<int>> &edges, int n, int src, int dest)
    {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        generateGraph(edges, graph);
        auto orgGraph = graph;

        vector<int> parent(n, -1);
        int flow = 0;
        while (bfs(graph, parent, n, src, dest))
        {
            int minFlow = INT_MAX;
            for (int u = dest; u != src; u = parent[u])
                minFlow = min(minFlow, graph[parent[u]][u]);
            
            flow += minFlow;
            for (int u = dest; u != src; u = parent[u])
            {
                graph[parent[u]][u] -= minFlow;
                graph[u][parent[u]] += minFlow;
            }
        }
        
        minCutEdges(graph, orgGraph, n, src);
        return flow;
    }
};