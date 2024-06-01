#include "../../headers.h"

class Solution
{
    vector<vector<unordered_map<int, int>>> dp;
    int rec(vector<int> &v, vector<int> &val, int i, int j, int x)
    {
        if (j == val.size())
            return i == v.size() ? 0 : 1e8;
        if (i == v.size())
            return 1e8;
        if (dp[i][j].count(x))
            return dp[i][j][x];
        
        int res = 1e8;
        if ((x & v[i]) == val[j])
            res = rec(v, val, i + 1, j + 1, INT_MAX) + v[i];
        return dp[i][j][x] = min(res, rec(v, val, i + 1, j, x & v[i]));
    }

public:
    int minimumValueSum(vector<int> &v, vector<int> &val)
    {
        dp.resize(v.size(), vector<unordered_map<int, int>>(val.size()));
        int ans = rec(v, val, 0, 0, INT_MAX);
        return ans == 1e8 ? -1 : ans;
    }
};