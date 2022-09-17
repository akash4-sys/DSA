#include "../../headers.h"

class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> g(n, vector<int>(n, 0));
        vector<int> cnt(n);
        for (auto e : edges)
        {
            cnt[e[0]]++;
            cnt[e[1]]++;
            g[e[0]][e[1]]++;
            g[e[1]][e[0]]++;
        }

        int ans = 1;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                    ans = max(ans, (cnt[i] + cnt[j] - g[i][j]));
        return ans;
    }
};