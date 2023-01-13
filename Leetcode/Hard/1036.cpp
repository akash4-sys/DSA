#include "../../headers.h"

class Solution
{
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}, n = 1e6;
    bool dfs(map<pair<int, int>, int> &mp, vector<int> &t, vector<int> &s, int i, int j)
    {
        if (i < 0 || j < 0 || i >= n || j >= n || mp.count({i, j}))
            return 0;
        if ((i == t[0] && j == t[1]) || (abs(i - s[0]) + abs(j - s[1]) > 200))
            return 1;
        mp[{i, j}] = 1;
        for (auto [x, y] : dirs)
            if (dfs(mp, t, s, i + x, j + y))
                return 1;
        return 0;
    }

public:
    bool isEscapePossible(vector<vector<int>> &bc, vector<int> &s, vector<int> &t)
    {
        map<pair<int, int>, int> mp, rmp;
        for (auto b : bc)
            mp[{b[0], b[1]}] = rmp[{b[0], b[1]}] = 1;
        return dfs(mp, t, s, s[0], s[1]) && dfs(rmp, s, t, t[0], t[1]);
    }
};