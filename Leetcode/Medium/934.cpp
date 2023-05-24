#include "../../headers.h"

// Time Complexity - O(N^2)
// Space Complexity - O(N^2)

class Solution
{
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}, n;
    queue<pair<int, int>> q;

    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != 1)
            return;
        q.push({i, j});
        grid[i][j] = -1;
        for (auto [dx, dy] : dirs)
            dfs(grid, i + dx, j + dy);
    }

public:
    int shortestBridge(vector<vector<int>> &grid)
    {
        n = grid.size();
        for (int i = 0; i < n && q.empty(); i++)
            for (int j = 0; j < n && q.empty(); j++)
                if (grid[i][j])
                    dfs(grid, i, j);
        
        for (int dist = 0; !q.empty(); dist++)
            for (int k = q.size(); k; k--)
            {
                int i = q.front().first, j = q.front().second;
                q.pop();
                for (auto [dx, dy] : dirs)
                {
                    int x = i + dx, y = j + dy;
                    if (x >= 0 && x < n && y >= 0 && y < n)
                    {
                        if (grid[x][y] == 1)
                            return dist;
                        else if (!grid[x][y])
                            q.push({x, y}), grid[x][y] = -1;
                    }
                }
            }
        return -1;
    }
};