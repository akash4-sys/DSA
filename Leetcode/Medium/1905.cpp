#include "../../headers.h"

class Solution {
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int M, N;
    void dfs(vector<vector<int>> &grid2, int x, int y, int val) {
        if (grid2[x][y] == val) return;
        grid2[x][y] = val;
        for (auto d : dir) {
            int i = x + d[0], j = y + d[1];
            if (i < 0 || i >= M || j < 0 || j >= N) continue;
            dfs(grid2, i, j, val);
        }
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        M = grid1.size(), N = grid1[0].size();
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid1[i][j] == 0) dfs(grid2, i, j, 0);
            }
        }
        int cnt = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (grid2[i][j] == 1) {
                    dfs(grid2, i, j, 0);
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};


// Not working can't find why
class Solution
{
public:
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int ans = 0, x = 0, y = 0;

    void checkAround(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid2.size() || j >= grid2[0].size() || !grid2[i][j])
            return;
        grid2[i][j] = 0;
        x++;
        y += grid1[i][j];
        for (auto d : dir)
            checkAround(grid1, grid2, i + d[0], j + d[1]);
        return;
    }

    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        for (int i = 0; i < grid1.size(); i++)
        {
            for (int j = 0; j < grid1[0].size(); j++)
            {
                if (!grid2[i][j] && grid2[i][j] != grid1[i][j])  // something wrong from this line replace with || to see changes
                    continue;
                grid2[i][j] = 0;
                y += grid1[i][j];
                for (auto d : dir)
                {
                    checkAround(grid1, grid2, i + d[0], j + d[1]);
                    if(x == y && x != 0)
                        ans++;
                }
            }
        }
        return ans;
    }
};