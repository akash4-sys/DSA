#include "../../headers.h"

// @ doing this without actually manipulating the given grid is even more simple and won't be considered in space complexity

// Time Complexity - O(N ^ 2)
// Space Complexity - O(1)
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &grid)
    {
        int maxD = grid.size() + grid[0].size();
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(!grid[i][j]) continue;
                int top = maxD, left = maxD;
                if(i - 1 >= 0) top = grid[i - 1][j];
                if(j - 1 >= 0) left = grid[i][j - 1];
                grid[i][j] = min(top, left) + 1;
            }
        
        for(int i = grid.size() - 1; i >= 0; i--)
            for(int j = grid[0].size() - 1; j >= 0; j--)
            {
                if(!grid[i][j]) continue;
                int bottom = maxD, right = maxD;
                if(i + 1 < grid.size()) bottom = grid[i + 1][j];
                if(j + 1 < grid[0].size()) right = grid[i][j + 1];
                grid[i][j] = min(grid[i][j], min(bottom, right) + 1);
            }
        return grid;
    }
};



// Time Complexity - O(N ^ 2)
// Space Complexity - O(N)
class Solution
{
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (!grid[i][j])
                    q.push({i, j});
                else
                    grid[i][j] = -1;

        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();
            for (auto d : dirs)
            {
                int x = i + d[0], y = j + d[1];
                if (x >= 0 && y >= 0 && y < grid[0].size() && x < grid.size() && grid[x][y] == -1)
                    grid[x][y] = grid[i][j] + 1, q.push({x, y});
            }
        }
        return grid;
    }
};