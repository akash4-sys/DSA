#include "../../headers.h"

class Solution
{
    int dfs(vector<vector<int>> &v, int i, int j)
    {
        if (i < 0 || j < 0 || i >= v.size() || j >= v[0].size() || v[i][j] >= 0)
            return 0;
        v[i][j] = 0;
        int res = 1;
        for (auto [dx, dy] : vector<pair<int, int>>{{1, 0}, {0, 1}, {-1, 0}, {0, -1}})
            res += dfs(v, i + dx, j + dy);
        return res;
    }

public:
    int countNegatives(vector<vector<int>> &v)
    {
        return dfs(v, v.size() - 1, v[0].size() - 1);
    }
};