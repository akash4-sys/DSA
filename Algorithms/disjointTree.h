#pragma once

#include <vector>
#include <numeric>

class DSU
{
    std::vector<int> parent;

public:
    DSU(int n) : parent(n)
    {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int findParent(int u)
    {
        return parent[u] == u ? u : parent[u] = findParent(parent[u]);
    }

    bool Union(int u, int v)
    {
        int uPar = findParent(u), vPar = findParent(v);
        if (uPar == vPar)
            return 0;
        parent[uPar] = vPar;
        return 1;
    }
};

class DSUW
{
    std::vector<int> parent;

public:
    DSUW(int n) : parent(n, -1) {}

    int findParent(int u)
    {
        return (parent[u] < 0) ? u : parent[u] = findParent(parent[u]);
    }

    bool Union(int u, int v)
    {
        int uPar = findParent(u), vPar = findParent(v);
        if (uPar == vPar)
            return 0;
        if (parent[uPar] < parent[vPar])
        {
            parent[uPar] += parent[vPar];
            parent[vPar] = uPar;
        }
        else
        {
            parent[vPar] += parent[uPar];
            parent[uPar] = vPar;
        }
        return 1;
    }
};