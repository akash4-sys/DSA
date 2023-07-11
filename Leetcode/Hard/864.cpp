#include "../../headers.h"

class Solution
{
public:
    int shortestPathAllKeys(vector<string> &grid)
    {
        int m = grid.size(), n = grid[0].size(), dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int steps = 0, totalKeys = 0;
        vector vis(m, vector(n, vector<bool>(64, 0)));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '@') {
                    q.push({(i * n) + j, 0});
                    vis[i][j][0] = 1;
                }
                totalKeys += isalpha(grid[i][j]) && islower(grid[i][j]);
            }

        while (!q.empty())
        {
            for (int sz = q.size(); sz; sz--)
            {
                auto [idx, kmap] = q.front();
                int i = idx / n, j = idx % n;
                q.pop();
                if (kmap == (1 << totalKeys) - 1)
                    return steps;
                for (auto [dx, dy] : dirs)
                {
                    int x = i + dx, y = j + dy, tmap = kmap;
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '#')
                        continue;
                    if (isupper(grid[x][y]) && !(kmap & (1 << (grid[x][y] - 'A'))))
                        continue;
                    if (islower(grid[x][y]))
                        tmap = kmap | (1 << (grid[x][y] - 'a'));
                    if (!vis[x][y][tmap]) {
                        vis[x][y][tmap] = 1;
                        q.push({(x * n) + y, tmap});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};


// TLE

class Solution
{
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}, keys = 0, m, n;
    int dfs(vector<string> &grid, int i, int j, int kmap, int kc, vector<int> vis)
    {
        if (kc == keys)
            return 0;

        vis[i] |= (1 << j);
        int res = 100000;
        for (auto [dx, dy] : dirs)
        {
            int x = i + dx, y = j + dy;
            if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != '#' && !(vis[x] & (1 << y)))
            {
                char c = grid[x][y];
                int lock = isupper(c) ? 1 << (c - 'A') : 0, key = islower(c) ? 1 << (c - 'a') : 0;
                if (c == '.' || (isupper(c) && (kmap & lock)) || (islower(c) && (kmap & key)))
                    res = min(res, dfs(grid, x, y, kmap, kc, vis) + 1);
                else if (islower(c) && (kmap & key) == 0)
                    res = min(res, dfs(grid, x, y, kmap | key, kc + 1, vector<int>(m, 0)) + 1);
            }
        }
        return res;
    }

public:
    int shortestPathAllKeys(vector<string> &grid)
    {
        m = grid.size(), n = grid[0].size();
        int st_i, st_j;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '@')
                    st_i = i, st_j = j;
                keys += isalpha(grid[i][j]) && islower(grid[i][j]);
            }

        grid[st_i][st_j] = '.';
        int ans = dfs(grid, st_i, st_j, 0, 0, vector<int>(m, 0));
        return ans <= 1000 ? ans : -1;
    }
};