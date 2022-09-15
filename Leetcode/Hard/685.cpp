#include "../../headers.h"

// Union By Weight
class DSU
{
    vector<int> par;

public:
    DSU(int n) : par(n)
    {
        par = vector<int>(n, -1);
    }
    int find(int v)
    {
        if (par[v] < 0)
            return v;
        return par[v] = find(par[v]);
    }
    bool Union(int x, int y)
    {
        int xp = find(x), yp = find(y);
        if (xp == yp)
            return false;
        if (par[xp] < par[yp])
            par[xp] += par[yp], par[yp] = xp;
        else
            par[yp] += par[xp], par[xp] = yp;
        return true;
    }
};

class Solution
{
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &e)
    {
        int x = -1, y = -1, n = e.size();
        DSU du(n + 1);
        vector<int> indegree(n + 1, -1);

        for (int i = 0; i < n; i++)
        {
            if (indegree[e[i][1]] != -1)
            {
                y = indegree[e[i][1]];
                x = i;
                break;
            }
            indegree[e[i][1]] = i;
        }

        for (int i = 0; i < n; i++)
        {
            if (i == x)
                continue;
            if (!du.Union(e[i][0], e[i][1]))
                return (x != -1) ? e[y] : e[i];
        }
        return e[x];
    }
};