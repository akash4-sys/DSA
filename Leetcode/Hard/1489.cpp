#include "../../headers.h"

class DSU
{
    vector<int> par;
    
public:
    DSU(int n) : par(n) {
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        return u == par[u] ? u : par[u] = find(par[u]);
    }

    bool Union(int u, int v) {
        int up = find(u), vp = find(v);
        if (up == vp)
            return 0;
        par[up] = vp;
        return 1;
    }
};

class Solution
{
    int mstWeight(vector<vector<int>> &edges, int n, int skipV = -1, int addEdge = -1)
    {
        int minWeight = 0;
        DSU uf(n);
        if (addEdge != -1)
            uf.Union(edges[addEdge][0], edges[addEdge][1]), minWeight += edges[addEdge][2];
        
        for (int i = 0; i < edges.size(); i++)
            if (i != skipV && uf.Union(edges[i][0], edges[i][1]))
                minWeight += edges[i][2];
        
        for (int i = 0; i < n; i++)
            if (uf.find(i) != uf.find(0))
                return INT_MAX;
        return minWeight;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        for (int i = 0; i < edges.size(); i++)
            edges[i].push_back(i);
        sort(edges.begin(), edges.end(), [&](const auto &a, const auto &b){
            return a[2] < b[2];
        });

        vector<int> critIdx, pCritIdx;
        int minWeight = mstWeight(edges, n);
        for (int i = 0; i < edges.size(); i++)
            if (mstWeight(edges, n, i) > minWeight)
                critIdx.push_back(edges[i][3]);
            else if (mstWeight(edges, n, -1, i) == minWeight)
                pCritIdx.push_back(edges[i][3]);
        return {critIdx, pCritIdx};
    }
};

// @lc app=leetcode id=1489 lang=cpp