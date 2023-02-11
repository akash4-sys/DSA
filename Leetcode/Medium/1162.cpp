#include "../../headers.h"

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid.size(); j++)
                if (grid[i][j])
                    q.push({i, j});
        
        int ans = -1;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                auto [i, j] = q.front();
                q.pop();
                for (int dirs[4][2]{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; auto dr : dirs)
                {
                    int x = dr[0] + i, y = dr[1] + j;
                    if (x >= 0 && y >= 0 && x < grid.size() && y < grid.size() && !grid[x][y])
                        grid[x][y] = 1, q.push({x, y});
                }
            }
            ans++;
        }
        return !ans ? -1 : ans;
    }
};

// @lc app=leetcode id=1162 lang=cpp