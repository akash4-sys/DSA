#include "../../headers.h"

/*
 * @lc app=leetcode id=1631 lang=cpp
 * [1631] Path With Minimum Effort
 */

// * Dijkstra's algorihtm on a grid

typedef pair<int, int> p;
typedef tuple<int, int, int> t;
vector<p> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        priority_queue<t, vector<t>, greater<t>> pq;
        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        pq.push({0, 0, 0});
        effort[0][0] = 0;

        while (!pq.empty())
        {
            auto [eff, i, j] = pq.top();
            pq.pop();
            if (i == n - 1 && j == m - 1)
                return effort[n - 1][m - 1];
            for (auto [dx, dy] : dirs)
            {
                int x = i + dx, y = j + dy;
                if (x < 0 || x >= n || y < 0 || y >= m)
                    continue;
                int currEff = max(eff, abs(grid[x][y] - grid[i][j]));
                if (currEff < effort[x][y])
                    effort[x][y] = currEff, pq.push({currEff, x, y});
            }
        }
        return -1;
    }
};

