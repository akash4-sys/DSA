#include "headers.h"

class Solution
{
public:
    int maxSum(vector<vector<int>> &g)
    {
        int ans = INT_MIN;
        for(int i = 0; i < g.size() - 2; i++)
        {
            int top = g[i][0] + g[i][1] + g[i][2];
            int down = g[i + 2][0] + g[i + 2][1] + g[i + 2][2];
            ans = max(top + down + g[i + 1][1], ans);
            for(int j = 1; j < g[0].size() - 2; j++)
            {
                top -= g[i][j - 1];
                top += g[i][j + 2];
                down -= g[i + 2][j - 1];
                down += g[i + 2][j + 2];
                ans = max(top + down + g[i + 1][j + 1], ans);
            }
        }
        return ans;
    }
};