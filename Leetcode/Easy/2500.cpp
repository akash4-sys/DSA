#include "headers.h"

class Solution
{
public:
    int deleteGreatestValue(vector<vector<int>> &grid)
    {
        int ans = 0;
        for(auto &v: grid)
            sort(v.begin(), v.end(), greater<int>());

        for(int j = 0; j < grid[0].size(); j++)
        {
            int m = INT_MIN;
            for(int i = 0; i < grid.size(); i++)
                m = max(m, grid[i][j]);
            ans += m;
        }
        return ans;
    }
};