#include "../../headers.h"


// Wrong approach
class Solution
{
public:
    vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int ans = 0;

    bool checkForMore(vector<vector<int>> &grid, int i, int j)
    {
        if(i == 0 || j == 0 || i == grid.size()-1 || j == grid[0].size()-1)
            return false;
        
        for(auto d: dirs)
        {
            int I = i + d[0], J = j + d[1];
            if(I < 0 || J < 0 || I >= grid.size() || J >= grid[0].size() || !grid[I][J])
                continue;
            grid[i][j] = 0;
            ans++;
            checkForMore(grid, I, J);
        }
    }

    int numEnclaves(vector<vector<int>> &grid)
    {
        for (int i = 1; i < grid.size() - 1; i++)
        {
            for (int j = 1; j < grid.size() - 1; j++)
            {
                if (!grid[i][j])
                    continue;
                ans++;
                checkForMore(grid, i, j);
            }
        }
        return ans;
    }
};