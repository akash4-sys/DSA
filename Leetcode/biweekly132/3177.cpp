#include "../../headers.h"

class Solution
{
    int dp[502][26];
    int rec(vector<int> &v, int i, int k)
    {
        if (i == v.size())
            return 0;
        if (dp[i + 1][k] != -1)
            return dp[i + 1][k];
        
        int res = 0;
        for (int j = i + 1; j < v.size(); j++)
            if (i == -1 || v[i] == v[j])
                res = max(res, rec(v, j, k) + 1);
            else if (v[i] != v[j] && k)
                res = max(res, rec(v, j, k - 1) + 1);
        return dp[i + 1][k] = res;
    }

public:
    int maximumLength(vector<int> &v, int k)
    {
        memset(dp, -1, sizeof(dp));
        return rec(v, -1, k);
    }
};