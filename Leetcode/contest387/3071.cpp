#include "../../headers.h"

class Solution
{
    int n;
    int convertToY(vector<vector<int>> grid, int y, int s)
    {
        int res = 0;
        for (int i = 0; i <= n / 2; i++) {
            res += grid[i][i] != y;
            grid[i][i] = 3;
        }

        for (int i = 0, j = n - 1; i < n / 2; i++, j--) {
            res += grid[i][j] != y;
            grid[i][j] = 3;
        }

        for (int i = n / 2 + 1; i < n; i++) {
            res += grid[i][n / 2] != y;
            grid[i][n / 2] = 3;
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] != 3)
                    res += grid[i][j] != s;
        return res;
    }

public:
    int minimumOperationsToWriteY(vector<vector<int>> &grid)
    {
        n = grid.size();
        int ans = INT_MAX;
        for (int i = 0; i <= 2; i++)
            for (int j = 0; j <= 2; j++)
                if (i != j)
                    ans = min(ans, convertToY(grid, i, j));
        return ans;
    }
};