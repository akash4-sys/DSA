#include "../../headers.h"

class DSU
{
    vector<int> par;

public:
    DSU(int n) : par(n)
    {
        iota(par.begin(), par.end(), 0);
    }

    int find(int x)
    {
        return x == par[x] ? x : par[x] = find(par[x]);
    }

    bool Union(int x, int y)
    {
        int xp = find(x), yp = find(y);
        if (xp == yp)
            return false;
        par[xp] = yp;
        return true;
    }
};

class Solution
{
    int n;
    int findMST(vector<vector<int>> &edges, int skip, int force = -1)
    {
        int minW = 0;
        DSU uf(n);
        if(force != -1)
            uf.Union(edges[force][0], edges[force][1]), minW += edges[force][2];

        for (int i = 0; i < edges.size(); i++)
        {
            if (i == skip)
                continue;
            if (uf.Union(edges[i][0], edges[i][1]))
                minW += edges[i][2];
        }

        for(int i = 0; i < n; i++)
            if(uf.find(i) != uf.find(0))
                return INT_MAX;
        return minW;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        this->n = n;
        vector<int> crit, pCrit;
        for(int i = 0; i < n; i++)
            edges[i].push_back(i);
        sort(edges.begin(), edges.end(), [](auto &e1, auto &e2) { return e1[2] < e2[2]; });
        
        int minW = findMST(edges, -1);
        for(int i = 0; i < edges.size(); i++)
            if(findMST(edges, i) > minW)
                crit.push_back(i);
            else if(findMST(edges, -1, i) == minW)
                pCrit.push_back(i);
        
        return { crit, pCrit };
    }
};

// @lc app=leetcode id=1489 lang=cpp