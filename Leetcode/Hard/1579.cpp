#include "../../headers.h"

class DSU
{
    int components;
    vector<int> parent;

public:
    DSU(int n) : parent(n + 1), components(n)
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
        components--;
        return 1;
    }

    bool oneComp()
    {
        return components == 1;
    }
};


class Solution
{
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges)
    {
        sort(edges.begin(), edges.end(), greater<vector<int>>());
        int minEdges = 0;
        DSU bob(n), alice(n);

        for (auto &e : edges)
        {
            if (e[0] == 3)
                minEdges += (bob.Union(e[1], e[2]) | alice.Union(e[1], e[2]));
            else if (e[0] == 2)
                minEdges += bob.Union(e[1], e[2]);
            else if (e[0] == 1)
                minEdges += alice.Union(e[1], e[2]);
        }
        return (bob.oneComp() && alice.oneComp()) ? edges.size() - minEdges : -1;
    }
};