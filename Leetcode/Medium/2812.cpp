#include "../../headers.h"

class Solution
{
public:
    int maximumSafenessFactor(vector<vector<int>> &g)
    {
        int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}, n = g.size();
        queue<int> q;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (g[i][j])
                    q.push(i * 1000 + j);
        
        while (!q.empty())
        {
            int hash = q.front();
            q.pop();
            int i = hash / 1000, j = hash % 1000;
            for (auto [dx, dy] : dirs)
            {
                int x = i + dx, y = j + dy;
                if (min(x, y) >= 0 && max(x, y) < n && !g[x][y])
                    g[x][y] = g[i][j] + 1, q.push(x * 1000 + y);
            }
        }

        priority_queue<vector<int>> pq;
        pq.push({g[0][0], 0});
        while (pq.top()[1] / 1000 < n - 1 || pq.top()[1] % 1000 < n - 1)
        {
            int w = pq.top()[0], hash = pq.top()[1];
            int i = hash / 1000, j = hash % 1000;
            pq.pop();
            for (auto [dx, dy] : dirs)
            {
                int x = i + dx, y = j + dy;
                if (min(x, y) >= 0 && max(x, y) < n && g[x][y] != -1)
                    pq.push({min(w, g[x][y]), x * 1000 + y}), g[x][y] = -1;
            }
        }
        return pq.top()[0] - 1;
    }
};