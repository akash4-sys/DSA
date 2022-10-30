#include "../../headers.h"

static vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, int w)
    {
        int n = grid.size(), m = grid[0].size();
        queue<vector<int>> q;
        vector<vector<int>> vis(n, vector<int>(m, -1));
        q.push({0, w, 0, 0});

        while (!q.empty())
        {
            int dist = q.front()[0], k = q.front()[1], i = q.front()[2], j = q.front()[3];
            q.pop();
            if (i == n - 1 && j == m - 1)
                return dist;
            for (auto &[dx, dy] : dirs)
            {
                int x = i + dx, y = j + dy, currK = k - grid[x][y];
                if (x < 0 || y < 0 || x >= n || y >= m || (grid[x][y] && !k) || (vis[x][y] != -1 && vis[x][y] >= currK))
                    continue;
                vis[x][y] = currK;
                q.push({dist + 1, currK, x, y});
            }
        }
        return -1;
    }
};