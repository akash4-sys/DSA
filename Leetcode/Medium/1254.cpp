#include "../../headers.h"

static int dirs[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
class Solution
{
public:
    bool dfs(vector<vector<int>> &m, int i, int j)
    {
        if (i < 0 || j < 0 || i == m.size()|| j == m[0].size())
            return 0;
        if (m[i][j])
            return 1;
        m[i][j] = 1;
        bool res = 1;
        for (auto [dx, dy] : dirs)
            res &= dfs(m, i + dx, j + dy);
        return res;
    }
    
    int closedIsland(vector<vector<int>> &m)
    {
        int ans = 0;
        for (int i = 0; i < m.size(); i++)
            for (int j = 0; j < m[0].size(); j++)
                if (!m[i][j])
                    ans += dfs(m, i, j);
        return ans;
    }
};