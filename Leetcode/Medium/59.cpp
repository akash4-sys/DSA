#include "../../headers.h"

class Solution
{
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    vector<vector<int>> generateMatrix(int n)
    {
        int i = 0, j = -1, d = 0, x = 1, steps[2] = {n, n - 1};
        vector ans(n, vector<int>(n, 0));

        while (steps[d % 2])
        {
            for (int k = 0; k < steps[d % 2]; k++)
            {
                i += dir[d][0];
                j += dir[d][1];
                ans[i][j] = x++;
            }
            steps[d % 2]--;
            d = (d + 1) % 4;
        }
        return ans;
    }
};

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector ans(n, vector<int>(n, 0));
        int x = 1;
        for (int i = 0; i < n * n; i++)
        {
            for (int j = i; j < n - i; j++)
                ans[i][j] = x++;

            for (int j = i + 1; j < n - i; j++)
                ans[j][n - i - 1] = x++;

            for (int j = n - i - 2; n - i - 1 != i && j >= i; --j)
                ans[n - i - 1][j] = x++;
                
            for (int j = n - i - 2; n - i - 1 != i && j > i; --j)
                ans[j][i] = x++;
        }
        return ans;
    }
};