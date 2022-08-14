#include "headers.h"

class Solution
{
public:
    vector<vector<int>> largestLocal(vector<vector<int>> &grid)
    {
        vector<vector<int>> ans;
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
        int n = grid.size();
        for (int i = 1; i < n - 1; i++)
        {
            vector<int> temp;
            for (int j = 1; j < n - 1; j++)
            {
                int x = grid[i][j];
                for(auto d: dirs)
                    x = max(grid[i + d[0]][j + d[1]], x);
                temp.push_back(x);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};