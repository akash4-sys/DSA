#include "../../headers.h"

class Solution
{
public:
    bool satisfiesConditions(vector<vector<int>> &v)
    {
        int m = v.size(), n = v[0].size(), ans = 1;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (i + 1 < m)
                    ans &= (v[i][j] == v[i + 1][j]);
                if (j + 1 < n)
                    ans &= (v[i][j] != v[i][j + 1]);
            }
        return ans;
    }
};