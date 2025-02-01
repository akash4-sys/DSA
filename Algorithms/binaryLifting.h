#pragma once

#include <vector>
#include <queue>

using namespace std;

// @ Lowest common ancestor

class LCA
{
    int n, maxDepth;
    vector<int> depth;
    vector<vector<int>> ancestor;

    void dfs(vector<vector<int>> &g, int u, int par, int d) {
        ancestor[u][0] = par;
        depth[u] = d;
        for (int i = 1; i < maxDepth; i++)
            ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
        for (int &v : g[u])
            if (v != par)
                dfs(g, v, u, d + 1);
    }

public:
    LCA(int n, vector<vector<int>> &g) {
        this->n = n;
        maxDepth = log2(n) + 1;
        ancestor.resize(n, vector<int>(maxDepth, -1));
        depth.resize(n, 0);
        dfs(g, 0, 0, 0);
    }

    int lca(int u, int v) {
        if (depth[u] > depth[v])
                swap(u, v);

        for (int k = 0; (1 << k) <= depth[v] - depth[u]; k++)
            if ((1 << k) & depth[v] - depth[u])
                v = ancestor[v][k];

        for (int k = maxDepth - 1; k >= 0; k--)
            if (ancestor[u][k] != ancestor[v][k])
                u = ancestor[u][k], v = ancestor[v][k];
        return u == v ? u : ancestor[u][0];
    }
};


class TreeAncestor
{
    int n, maxDepth;
    vector<vector<int>> ancestor;
public:
    TreeAncestor(int n, vector<int> par)
    {
        this->n = n;
        maxDepth = log2(n) + 1;
        ancestor = vector(n, vector<int>(maxDepth, -1));

        for (int i = 0; i < n; i++)
            ancestor[i][0] = par[i];

        for (int j = 1; j < maxDepth; j++)
            for (int i = 0; i < n; i++)
                if (ancestor[i][j - 1] != -1)
                    ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
    }

    int getKthAncestor(int node, int k)
    {
        for (int i = 0; i < maxDepth; i++)
            if (k & (1 << i))
            {
                node = ancestor[node][i];
                if (node == -1)
                    return -1;
            }
        return node;
    }
};