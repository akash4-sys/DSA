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

    int findPar(int u) {
        return par[u] < 0 ? u : par[u] = findPar(par[u]);
    }

    int componentSize(int u) {
        return -par[findPar(u)];
    }

    bool Union(int u, int v)
    {
        u = findPar(u), v = findPar(v);
        if (u == v)
            return 0;
        if (par[u] > par[v])
            swap(u, v);
        par[u] += par[v];
        par[v] = u;
        return 1;
    }
};