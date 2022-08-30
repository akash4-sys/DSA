#include "../../headers.h"

// Time Complexity - O(N^2)
// Space Complexity - O(N)

class Solution
{
public:
    void rotate(vector<vector<int>> &grid)
    {
        int n = grid.size(), st = 0;
        stack<int> sr, sl;
        while (st < n - 1)
        {
            int x = grid[st][n - 1];
            for (int it = st; it < n; it++)
            {
                sr.push(grid[it][n - 1]);
                grid[it][n - 1] = grid[st][it];
                if (it == n - 1)
                    grid[it][n - 1] = x;
                sl.push(grid[it][st]);
                grid[it][st] = grid[n - 1][it];
            }
            for (int it = st; it < n; it++)
            {
                grid[n - 1][it] = sr.top();
                sr.pop();
                grid[st][it] = sl.top();
                sl.pop();
            }
            st++;
            n--;
        }
    }
};




// Time Complexity - O(N^2)
// Space Complexity - O(1)

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
};