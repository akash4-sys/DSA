#include "../../headers.h"

#define t tuple<int, int, int>
class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        static int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int ans = 0;
        priority_queue<t, vector<t>, greater<t>> pq;
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty()) 
        {
            auto [c, i, j] = pq.top();
            pq.pop();
            grid[i][j] = -1;
            ans = max(ans, c);
            if (i == grid.size() - 1 && i == j)
                return ans;
            for (auto [dx, dy] : dirs)
            {
                int x = i + dx, y = j + dy;
                if (x >= 0 && x < grid.size() && y >= 0 && y < grid.size() && grid[x][y] != -1)
                    pq.push({grid[x][y], x, y});
            }
        }
        return -1;
    }
};

// @lc app=leetcode id=778 lang=cpp