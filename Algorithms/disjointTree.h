#pragma once

#include <vector>
#include <numeric>

using namespace std;

class DSU
{
    vector<int> parent;

public:
    DSU(int n) : parent(n)
    {
        iota(parent.begin(), parent.end(), 0);
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
    vector<int> par;
public:

    DSUW(int n) : par(n, -1) {}

    int findPar(int u)
    {
        for (; par[u] > 0; u = par[u]);
        return u;
        // return (parent[u] < 0) ? u : parent[u] = findParent(parent[u]);  recursive
    }

    bool Union(int u, int v)
    {
        int up = findPar(u), vp = findPar(v);
        if (up == vp)
            return 0;
        
        if (par[up] < par[vp])
            par[up] += par[vp], par[vp] = up;
        else
            par[vp] += par[up], par[up] = vp;
        return 1;
    }
};