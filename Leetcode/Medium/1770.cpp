#include "../../headers.h"

class Solution
{
    int recurse(vector<vector<int>>& dp, vector<int> &v, vector<int> &m, int l, int i)
    {
        if(i >= m.size())
            return 0;
        if(dp[l][i] != INT_MIN)
            return dp[l][i];
        int r = v.size() - (i - l + 1);
        return dp[l][i] = max(v[l] * m[i] + recurse(dp, v, m, l + 1, i + 1), v[r] * m[i] + recurse(dp, v, m, l, i + 1));
    }
public:
    int maximumScore(vector<int> &v, vector<int> &m)
    {
        vector<vector<int>> dp(1001, vector<int>(1001, INT_MIN));
        return recurse(dp, v, m, 0, 0);
    }
};