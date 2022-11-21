#include "../../headers.h"

class Solution
{
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int nearestExit(vector<vector<char>> &grid, vector<int> &pos)
    {
        queue<tuple<int, int, int>> q;
        q.push({pos[0], pos[1], 0});
        while(!q.empty())
        {
            auto [i, j, d] = q.front();
            q.pop();
            if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '+')
                continue;
            if((i == 0 || i == grid.size() - 1 || j == 0 || j == grid[0].size() - 1) && (i != pos[0] || j != pos[1]))
                return d;
            grid[i][j] = '+';
            for(auto [x, y]: dirs)
                q.push({i + x, j + y, d + 1});
        }
        return -1;
    }
};