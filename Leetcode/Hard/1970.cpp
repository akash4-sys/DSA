#include "../../headers.h"

class Solution
{
    vector<int> par;

    int findPar(int u)
    {
        return (par[u] < 0) ? u : par[u] = findPar(par[u]);
    }

    void Union(int u, int v)
    {
        int uPar = findPar(u), vPar = findPar(v);
        if (uPar == vPar)
            return;
        par[vPar] = uPar;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector grid(row, vector<int>(col, 1));
        par = vector<int>((row * col) + 3, -1);

        int stnode = (row * col) + 1, endnode = (row * col) + 2;
        for (int j = 0; j < col; j++)
            Union(j, stnode), Union(((row - 1) * col) + j, endnode);

        for (int k = (row * col) - 1; k >= 0; k--)
        {
            int i = cells[k][0] - 1, j = cells[k][1] - 1, key = (i * col) + j;
            grid[i][j] = 0;
            for (auto [dx, dy] : dirs)
            {
                int x = i + dx, y = j + dy;
                if (x >= 0 && x < row && y >= 0 && y < col && !grid[x][y])
                    Union((x * col) + y, key);
                if (findPar(stnode) == findPar(endnode))
                    return k;
            }
        }
        return -1;
    }
};


class Solution
{
    int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    bool dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || !grid[i][j])
            return 0;
        if (i == grid.size() - 1)
            return 1;

        grid[i][j] = 0;
        for (auto [dx, dy] : dirs)
            if (dfs(grid, i + dx, j + dy))
                return 1;
        return 0;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>> &cells)
    {
        int l = 1, r = row * col;
        while (l < r)
        {
            int mid = l + ((r - l) / 2), path = 0;
            vector grid(row, vector<int>(col, 1));
            for (int i = 0; i < mid; i++)
                grid[cells[i][0] - 1][cells[i][1] - 1] = 0;

            for (int j = 0; j < col; j++)
                if (dfs(grid, 0, j))
                {
                    path = 1;
                    break;
                }
            if (path)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};