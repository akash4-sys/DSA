#include "../../headers.h"

class Solution
{
public:
    void rotate(vector<vector<int>> &grid)
    {
        int n = grid.size();
        for (int i = 0; i < n / 2; i++)
            for (int j = i; j < n - i - 1; j++)
            {
                int temp = grid[i][j];
                grid[i][j] = grid[n - j - 1][i];
                grid[n - j - 1][i] = grid[n - i - 1][n - j - 1];
                grid[n - i - 1][n - j - 1] = grid[j][n - i - 1];
                grid[j][n - i - 1] = temp;
            }
    }
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        if(mat == target)
            return true;
        for(int i = 0; i < 3; i++)
        {
            rotate(mat);
            if(mat == target)
                return true;
        }
        return false;
    }
};