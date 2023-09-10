#include "../../headers.h"

class Solution
{
public:
    int minimumMoves(vector<vector<int>> &grid)
    {
        int ans = INT_MAX;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (grid[i][j] == 0)
                {
                    for (int x = 0; x < 3; x++)
                        for (int y = 0; y < 3; y++)
                            if (grid[x][y] > 1)
                            {
                                int dist = abs(x - i) + abs(y - j);
                                grid[x][y]--;
                                grid[i][j]++;
                                ans = min(ans, minimumMoves(grid) + dist);
                                grid[x][y]++;
                                grid[i][j]--;
                            }
                }
        return ans == INT_MAX ? 0 : ans;
    }
};