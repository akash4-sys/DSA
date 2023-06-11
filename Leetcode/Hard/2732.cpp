#include "headers.h"

class Solution
{
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid[0].size(), m = grid.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < m; i++)
        {
            int mask = 0;
            for (int j = 0; j < n; j++)
                mask |= (grid[i][j] << j);
            if (!mask)
                return {i};

            for (int j = 1; j < 32; j++)
                if (!(mask & j) && mp.count(j))
                    return {mp[j], i};
            mp[mask] = i;
        }
        return {};
    }
};