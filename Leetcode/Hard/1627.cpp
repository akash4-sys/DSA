#include "../../headers.h"

class DSU
{
    vector<int> par;
public:

    DSU(int n) : par(n, -1) {}

    int findPar(int u) {
        for (; par[u] > 0; u = par[u]);
        return u;
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

class Solution
{
public:
    vector<bool> areConnected(int n, int t, vector<vector<int>> &qrs)
    {
        vector<bool> ans;
        DSU dsu(n + 1);
        for (int z = t + 1; z <= n; z++)
            for (int m = z * 2; m <= n; m += z)
                dsu.Union(z, m);

        for (auto &q : qrs)
            ans.push_back(dsu.findPar(q[0]) == dsu.findPar(q[1]));
        return ans;
    }
};