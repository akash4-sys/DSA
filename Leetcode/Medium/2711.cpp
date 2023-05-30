#include "headers.h"

class Solution
{
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> &g)
    {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> ans(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                unordered_set<int> tl, br;
                for (int a = i - 1, b = j - 1; a >= 0 && b >= 0; a--, b--)
                    tl.insert(g[a][b]);
                for (int a = i + 1, b = j + 1; a < n && b < m; a++, b++)
                    br.insert(g[a][b]);
                ans[i][j] = abs((int)tl.size() - (int)br.size());
            }
        return ans;
    }
};