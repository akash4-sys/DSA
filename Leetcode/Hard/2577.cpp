#include "../../headers.h"

#define t tuple<int, int, int>
static int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class Solution
{
public:
    int minimumTime(vector<vector<int>> &grid)
    {
        if (grid[0][1] > 1 && grid[1][0] > 1) 
            return -1;
        priority_queue<t, vector<t>, greater<t>> pq;
        pq.push({0, 0, 0});
        while (!pq.empty())
        {
            auto [time, i, j] = pq.top();
            pq.pop();
            if (grid[i][j] == -1)
                continue;
            grid[i][j] = -1;
            if (i == grid.size() - 1 && j == grid[0].size() - 1)
                return time;
            for (auto [dx, dy] : dirs)
            {
                int x = i + dx, y = j + dy;
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] != -1)
                    pq.push({max(grid[x][y] + !((grid[x][y] - time) % 2), time + 1), x, y});
            }
        }
        return -1;
    }
};