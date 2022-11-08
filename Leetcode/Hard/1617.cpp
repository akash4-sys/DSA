#include "../../headers.h"

class Solution
{
    int dfs(vector<vector<int>> &g, int m, int i, int &n, int &d)
    {
        int maxd = 0;
        ++n;
        for(auto v: g[i])
            if(m & (1 << v))
            {
                int dia = 1 + dfs(g, m ^ (1 << v), v, n, d);
                d = max(d,  dia + maxd);
                maxd = max(maxd, dia);
            }
        return maxd;
    }

public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>> &edges)
    {
        vector<int> ans(n - 1, 0);
        vector<vector<int>> g(n);
        for (auto e : edges)
            g[e[0] - 1].push_back(e[1] - 1), g[e[1] - 1].push_back(e[0] - 1);
        
        for(int i = 3; i < (1 << n); i++)
            for(int j = 0; j < n; j++)
                if(i & (1 << j))
                {
                    int nodes = 0, d = 0;
                    dfs(g, i ^ (1 << j), j, nodes, d);
                    if(d && nodes == __builtin_popcount(i))
                        ans[d - 1]++;
                    break;
                }
        return ans;
    }
};