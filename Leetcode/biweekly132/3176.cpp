#include "../../headers.h"

class Solution
{
    int dp[502][502][26];
    int rec(vector<int> &v, int i, int j, int k)
    {
        if (i == v.size())
            return 0;

        int &memo = dp[i][j][k], res = 0;
        if (memo != -1)
            return memo;
        
        if (v[i] != v[j] && k > 0)
            res = rec(v, i + 1, i, k - 1) + 1;
        if (v[i] == v[j])
            res = rec(v, i + 1, i, k) + 1;
        return memo = max(res, rec(v, i + 1, j, k));
    }

public:
    int maximumLength(vector<int> &v, int k)
    {
        v.insert(v.begin(), *v.begin());
        memset(dp, -1, sizeof(dp));
        return rec(v, 1, 0, k);
    }
};