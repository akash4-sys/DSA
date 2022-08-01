#include "../../headers.h"

typedef pair<int, pair<int, int>> p;

class Solution
{
public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        // priority queue sorted according to distance first int in pair
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        vector<vector<bool>> vis(m, vector<bool>(n, false));

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});
        while (!pq.empty())
        {
            auto current = pq.top();
            int x = current.second.first;
            int y = current.second.second;
            vis[x][y] = true;
            pq.pop();

            for (auto d : dirs)
            {
                int newX = x + d[0], newY = y + d[1];
                if (newX < 0 || newY < 0 || newX >= m || newY >= n || vis[newX][newY])
                    continue;
                if (dist[newX][newY] > dist[x][y] + grid[newX][newY])
                {
                    dist[newX][newY] = dist[x][y] + grid[newX][newY];
                    pq.push({dist[newX][newY], {newX, newY}});
                }
            }
        }
        return dist[m-1][n-1];
    }
};