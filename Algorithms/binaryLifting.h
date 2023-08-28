#pragma once

#include <vector>
#include <queue>

using namespace std;

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