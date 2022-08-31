#include "../../headers.h"

class Solution
{
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> atl, pac;
    vector<vector<int>> ans;

    void dfs(vector<vector<int>> &h, int i, int j, vector<vector<bool>>& ocean)
    {
        if (ocean[i][j])
            return;
        ocean[i][j] = true;
        if(atl[i][j] && pac[i][j])
            ans.push_back({i, j});
        for (auto [dx, dy] : dirs)
            if (i + dx >= 0 && j + dy >= 0 && i + dx < h.size() && j + dy < h[0].size() && h[i][j] <= h[i + dx][j + dy])
                dfs(h, i + dx, j + dy, ocean);
        return;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &h)
    {
        int m = h[0].size(), n = h.size();
        if(!n)
            return {{}};

        atl = pac = vector<vector<bool>>(n, vector<bool>(m, false));
        for (int i = 0; i < m; i++)
            dfs(h, 0, i, pac), dfs(h, n - 1, i, atl);
        for (int i = 0; i < n; i++)
            dfs(h, i, 0, pac), dfs(h, i, m - 1, atl);
        return ans;
    }
};