#include "../../headers.h"

typedef array<int, 3> Point;

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &mp)
    {
        int m = mp.size(), n = mp[0].size(), dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, ans = 0, maxh = INT_MIN;
        priority_queue<Point, vector<Point>, greater<>> pq;
        vector<vector<bool>> vis(m, vector<bool>(n));

        for (int i = 0; i < m; i++)
        {
            pq.push({mp[i][0], i, 0});
            pq.push({mp[i][n - 1], i, n - 1});
            vis[i][0] = true;
            vis[i][n-1] = true;
        }

        for (int j = 0; j < n; j++)
        {
            pq.push({mp[0][j], 0, j});
            pq.push({mp[m - 1][j], m - 1, j});
            vis[0][j] = true;
            vis[m-1][j] = true;
        }

        while(pq.size())
        {
            auto [h, x, y] = pq.top();
            pq.pop();
            maxh = max(maxh, h);
            for(auto [dx, dy]: dirs)
            {
                int a = x + dx, b = y + dy;
                if(a < 0 || a >= m || b < 0 || b >= n || vis[a][b])
                    continue;
                vis[a][b] = true;
                if(mp[a][b] < maxh)
                    ans += maxh - mp[a][b];
                pq.push({ mp[a][b], a, b });
            }
        }
        return ans;
    }
};