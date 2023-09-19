#include "../../headers.h"

class Solution
{
    int dp[101][101];
    bool rec(vector<int> &pf, int m, int l, int r)
    {
        if (l == r)
            return 1;
        if (dp[l][r] != -1)
            return dp[l][r];
        
        for (int i = l; i <= r; i++)
            if ((pf[i + 1] - pf[l] >= m || i == l) && (pf[r + 1] - pf[i + 1] >= m || i + 1 == r))
                if (rec(pf, m, l, i) && rec(pf, m, i + 1, r))
                    return dp[l][r] = 1;
        return dp[l][r] = 0;
    }

public:
    bool canSplitArray(vector<int> &v, int m)
    {
        vector<int> pf(v.size() + 1, 0);
        for (int i = 0; i < v.size(); i++)
            pf[i + 1] = pf[i] + v[i];
        
        memset(dp, -1, sizeof(dp));
        return rec(pf, m, 0, v.size() - 1);
    }
};