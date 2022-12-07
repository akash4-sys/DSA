#include "../../headers.h"

#define vv vector<vector<int>>
#define vec vector<int>

// Dp on trees problem
// Re rooting problem

class Solution
{
    void countNodes(vv &g, vec &ans, vec &nodes, int u, int p)
    {
        for(auto v: g[u])
        {
            if(v == p)
                continue;
            countNodes(g, ans, nodes, v, u);
            nodes[u] += nodes[v];
            ans[u] += ans[v] + nodes[v];
        }
        ++nodes[u];
    }

    void ReRooting(vv &g, vec &ans, vec &nodes, int n, int u, int p)
    {
        for(auto v: g[u])
        {
            if(v == p)
                continue;
            ans[v] = ans[u] - nodes[v] + n - nodes[v];
            ReRooting(g, ans, nodes, n, v, u);
        }
    }

public:
    vec sumOfDistancesInTree(int n, vv &edges)
    {
        vv g(n);
        vec ans(n), nodes(n);
        for (auto e : edges)
            g[e[0]].push_back(e[1]), g[e[1]].push_back(e[0]);
        
        countNodes(g, ans, nodes, 0, -1);
        ReRooting(g, ans, nodes, n, 0, -1);
        return ans;
    }
};