#include "../../headers.h"

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int ans = 0, n = grid.size();
        vector t(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                t[i][j] = grid[j][i];

        for(auto r: grid)
            for(auto c: t)
                ans += r == c;
        return ans;
    }
};