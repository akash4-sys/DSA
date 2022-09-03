#include "../../headers.h"

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] == 1)
            return -1;

        int dirs[8][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
        int ans = 1, n = grid.size();
        queue<pair<int, int>> q{{{0, 0}}};

        while (!q.empty())
        {
            int cnt = q.size();
            while (cnt--)
            {
                auto [x, y] = q.front();
                q.pop();
                if (x == n - 1 && y == n - 1)
                    return ans;
                for (auto &[dx, dy] : dirs)
                {
                    if (x + dx < 0 || y + dy < 0 || x + dx >= n || y + dy >= n || grid[x + dx][y + dy])
                        continue;
                    grid[x + dx][y + dy] = 1;
                    q.push({x + dx, y + dy});
                }
            }
            ans++;
        }
        return -1;
    }
};