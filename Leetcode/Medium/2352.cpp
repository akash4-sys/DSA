#include "../../headers.h"

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int ans = 0, n = grid.size();
        vector<vector<int>> t(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                t[i][j] = grid[j][i];
        }
        for(auto i: grid)
        {
            for(auto j: t)
            {
                if(i == j)
                    ans++;
            }
        }
        return ans;
    }
};