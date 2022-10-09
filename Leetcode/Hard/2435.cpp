#include "headers.h"

class Solution
{
    int ans = 0, mod = 1e9 + 7;
    void checkPaths(vector<vector<int>> &grid, int k, int i, int j, int sum)
    {
        if (i == grid.size() - 1)
        {
            for(int r = j; r < grid[0].size(); r++)
                sum = (sum + grid[i][r]) % mod;
            if(sum % k == 0)
                ans++;
            return;
        }
        if (j == grid[0].size() - 1)
        {
            for(int r = i; r < grid.size(); r++)
                sum = (sum + grid[r][j]) % mod;
            if(sum % k == 0)
                ans++;
            return;
        }
        sum =  (sum + grid[i][j]) % mod;
        checkPaths(grid, k, i + 1, j, sum);
        checkPaths(grid, k, i, j + 1, sum);
        return;
    }

public:
    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        checkPaths(grid, k, 0, 0, 0);
        return ans;
    }
};